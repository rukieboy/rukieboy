#include "jsmn_cnas.h"

JsmnCnas::JsmnCnas()
	
{
	object_tokens = 0;
  skip_tokens = 0;
  lists = 0;
  list_tokens = 0;
  
	folderKeys = 0;
	fileKeys = 0;
	//constructor
}

JsmnCnas::~JsmnCnas()
{
	mMap.clear();
	mList.clear();
	//destructor
}

JsmnCnas* JsmnCnas::createJsmnCnas()
{
	return new JsmnCnas();
}

void JsmnCnas::getFList(char URL[])
{
    js = json_fetch(URL);
		tokens = json_tokenise(js);
    

    // state is the current state of the parser
    parse_state state = START;

    // stack is the state we return to when reaching the end of an object
    parse_state stack = STOP;

		
    for (size_t i = 0, j = 1; j > 0; i++, j--)
    {
        jsmntok_t *t = &tokens[i];

        // Should never reach uninitialized tokens
        log_assert(t->start != -1 && t->end != -1);

        if (t->type == JSMN_ARRAY || t->type == JSMN_OBJECT)
            j += t->size;

        switch (state)
        {
            case START:
            	/*
                if (t->type != JSMN_ARRAY)
                    log_die("Invalid response: root element must be array.");
                   
                if (t->size != 1)
                    log_die("Invalid response: array must have one element.");
							*/
							
							if (t->type != JSMN_OBJECT)
								printf("Invalid response: root element must be an object.");
                    //log_die("Invalid response: root element must be an object.");
								
								state = KEY;
                object_tokens = t->size;

                if (object_tokens == 0)
                    state = STOP;

                if (object_tokens % 2 != 0)
                	printf("Invalid response: object must have even number of children.");
                    //log_die("Invalid response: object must have even number of children.");

                break;

             case KEY:

                object_tokens--;

                if (t->type != JSMN_STRING)
                	printf("Invalid response: object keys must be strings.");
                    //log_die("Invalid response: object keys must be strings.");

                state = SKIP;//org

                for (size_t i = 0; i < sizeof(KEYS)/sizeof(char *); i++)
                {
                    if (json_token_streq(js, t, KEYS[i]))
                    {
                        printf("%s: \n", KEYS[i]);
                        state = LISTS;
                        break;
                    }
                }

                break;   

            case WRAPPER:
            	            	
                if (t->type != JSMN_OBJECT)
                	printf("Invalid response: wrapper must be an object.");
                    //log_die("Invalid response: wrapper must be an object.");

                state = OBJECT;
                object_tokens = t->size;
                break;

            case OBJECT:
            	            	
                object_tokens--;

                // Keys are odd-numbered tokens within the object
                if (object_tokens % 2 == 1)
                {
                    //if (t->type == JSMN_STRING && json_token_streq(js, t, "lists"))
                    if (t->type == JSMN_STRING && json_token_streq(js, t, "list"))
                    {
                    		printf(" object token_streq list \n");
                        state = LISTS;
                    }
                }
                else if (t->type == JSMN_ARRAY || t->type == JSMN_OBJECT)
                {
                    state = SKIP;
                    stack = OBJECT;
                    skip_tokens = t->size;
                }

                // Last object value
                if (object_tokens == 0)
                    state = STOP;

                break;

            case SKIP:
                skip_tokens--;

                if (t->type == JSMN_ARRAY || t->type == JSMN_OBJECT)
                    skip_tokens += t->size;

                if (skip_tokens == 0)
                    state = stack;

                break;

            case LISTS: //lists
                if (t->type != JSMN_ARRAY)
                	printf("Unknown lists value: expected array.");
                    //log_die("Unknown lists value: expected array.");

                lists = t->size;
                state = ARRAY;
                stack = ARRAY;

                // No lists found
                if (lists == 0)
                    state = STOP;

                break;

            case ARRAY:
            	  
            	  //printf("ARRAY lists = %d\n", lists);
            	  			
                lists--;

                list_tokens = t->size;
                state = LIST;
                //state = WRAPPER;

                // Empty list object
                if (list_tokens == 0)
                    state = STOP;

                // Last list object
                if (lists == 0)
                    stack = STOP;
								
								
																
                break;

            case LIST: //folder list = 10, file list = 12
            	
            			printf("============================================================================\n");
            			//printf(" LIST list_tokens = %d\n", list_tokens);
                	
                	if(!mMap.empty())
                	{
                		printf(" not clean mMap ! \n");
                		mMap.clear();
                	}
            	
            			if(list_tokens == 10)
            			{
            				state = FOLDERS;
            				tempKey = json_token_tostr(js, t);
                    //puts(str);
            			}
            			
            			else if(list_tokens == 12)
            			{
            				state = FILES;
            				tempKey = json_token_tostr(js, t);
                    //puts(str);
            			}
            			
            			
                 			
            			list_tokens--;

            		 break;
            case FOLDERS:
            case FOLDER_SKIP:
            			
            			
            		list_tokens--;
                // Keys are odd-numbered tokens within the object
                if (list_tokens % 2 == 1)
                {
                	
                		//if (t->type == JSMN_STRING && json_token_streq(js, t, FOLDERKEYS[folderKeys++]))
                		if (t->type == JSMN_STRING )
                		{
                			//folderKeys = i;
                			state = FOLDERS;
                			tempKey = json_token_tostr(js, t);
                    	//puts(str);
                		}
                		else
                		{
                			state = FOLDER_SKIP;
                		}
              
                    
                }
                // Only care about values in the FKIND state
                else if (state == FOLDERS)
                {
                    if (t->type != JSMN_STRING)
                    	printf("Invalid list name.");
                        //log_die("Invalid list name.");
			
                    tempValue= json_token_tostr(js, t);              
                   
                    state = FOLDERS;
                    
                     mMap[tempKey] = tempValue;
                }
                else if (t->type == JSMN_ARRAY || t->type == JSMN_OBJECT)
                {
                		printf(" else if end \n" );
                    state = SKIP;
                    stack = FOLDERS;
                    skip_tokens = t->size;
                }
                // Last object value
                if (list_tokens == 0)
                {	
                		//printf(" Last object value \n" );
                		mList.push_back(mMap);
                		mMap.clear();
                    state = stack;
								}
								
                break;
                
             case FILES:
             case FILE_SKIP:

                list_tokens--;
				
                // Keys are odd-numbered tokens within the object
                
                
                if (list_tokens % 2 == 1)
                {		
                	
										if (t->type == JSMN_STRING )
                		{
                			//folderKeys = i;
                			state = FILES;
                			//char *str = json_token_tostr(js, t);
                    	//puts(str);
                    	tempKey = json_token_tostr(js, t);
                		}
                		else
                		{
                			state = FILE_SKIP;
                		}

       							
                }
                // Only care about values in the FKIND state
                else if (state == FILES)
                {
                    if (t->type != JSMN_STRING)
                    	printf("Invalid list name.");
                        //log_die("Invalid list name.");
										

                    //char *str = json_token_tostr(js, t);
                    //puts(str);
                    tempValue = json_token_tostr(js, t);
                    
                   
                    state = FILES;
                    
                    
                    mMap[tempKey] = tempValue;
                }
                else if (t->type == JSMN_ARRAY || t->type == JSMN_OBJECT)
                {
                		printf(" else if end \n" );
                    state = SKIP;
                    stack = LIST;
                    skip_tokens = t->size;
                }

                // Last object value
                if (list_tokens == 0)
                {	
                		//printf(" Last object value \n" );
                		mList.push_back(mMap);
                		mMap.clear();
                    state = stack;
								}
								
                break;
                        
            case PRINT:
            	{
                //if (t->type != JSMN_STRING && t->type != JSMN_PRIMITIVE)
                    //log_die("Invalid response: object values must be strings or primitives.");

                char *str = json_token_tostr(js, t);
                puts(str);

                object_tokens--;
                state = KEY;

                if (object_tokens == 0)
                    state = STOP;

                break;
							}    

            case STOP:
                // Just consume the tokens
                break;

            default:
            	printf("Invalid state %u", state);
                //log_die("Invalid state %u", state);
        }
    }

}



int main(void) //for test
{
	JsmnCnas* jc = JsmnCnas::createJsmnCnas();
	jc->getFList(URL);

	JsmnCnas::mmMap tempMap;
	//JsmnCnas::map_it iter
	
	while(!jc->mList.empty())
	{
		//printf(" test1 = %c\n", jc->mList.front());
		tempMap = jc->mList.back();
		
		for(std::map<string,string>::iterator iter = tempMap.begin(); iter != tempMap.end(); iter++)
		{
			cout << iter ->first << " : ";
			cout << iter ->second <<endl;

		}
					cout << " =========================================================" << endl;
		jc->mList.pop_back();
		
		
		
	}
	
	
	
	return 0;
}
