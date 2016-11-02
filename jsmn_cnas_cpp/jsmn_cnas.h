#ifndef __JSMN_CNAS_H__
#define __JSMN_CNAS_H__

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#include <iostream>
#include <map>
#include <list>
#include <string>



#ifdef __cplusplus
extern "C"
{
#endif

#include "jsmn.h"

#include "json.h"
#include "log.h"
#include "buf.h"

#ifdef __cplusplus
}
#endif

typedef struct {
	char* fkind;
	char* folderId;
	char* folderName;
	int level;
	char* regDate;

} folders_t;

typedef struct {
	char* fkind;
	char* fileId;
	char* fileName;
	int fileSize;
	int silId;
	char* regDate;
} files_t;


//char URL[] = "https://api.twitter.com/1/lists/1.json";
char URL[] = "https://210.218.253.142:443/folders/files?authId=CNAS&libVer=1.0.0&sId=010089095555&osInfo=android_4.4.2&nwInfo=4G&devModel=LE-E250&carrierType=L&folderId=658442051&startNo=0&searchCount=20&order=N&devInfo=PHONE&noticePos=MA";
char *KEYS[] = { "list" };
char *FOLDERKEYS[] = { "fkind","folderId","folderName","level","regDate"};
char *FILEKEYS[] = { "fkind","fileId","fileName","fileSize","silId","regDate" };

using namespace std;

class JsmnCnas
{
	
	public:
		explicit JsmnCnas();
		~JsmnCnas();
		
		static JsmnCnas* createJsmnCnas();
		void getFList(char URL[]);
		
		
		typedef map<string,string> mmMap;
		typedef list<mmMap> ListOfMap;
		
		mmMap mMap;
		ListOfMap mList;

		mmMap::const_iterator map_it;
		list<mmMap>::iterator list_it;

	private:
		
		char *js;
		jsmntok_t *tokens;
		
		typedef enum {
        START, KEY,
        WRAPPER, OBJECT,
        LISTS, ARRAY, 
        LIST, FOLDER_SKIP,FOLDERS, FILES, FILE_SKIP,
        SKIP, PRINT,
        STOP
    } parse_state;
    
    size_t object_tokens;
    size_t skip_tokens;
    size_t lists;
    size_t list_tokens; 
		int folderKeys;
		int fileKeys;
		
		char* tempKey;
		char* tempValue;
		
		//std::map<string ,string > mMap;
		//std::list<map<string ,string>> mList;
		

		
		//mmMap mMap;
		//ListOfMap mList;
		
		//map<int,int>::iterator map_it;
		//list<map<mmMap>::iterator list_it;

    
};

#endif
