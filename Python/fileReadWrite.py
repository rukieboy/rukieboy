# file read / write 

import sys
def process_file(fileName):
	input_file = open(fileName, "r")
	for line in input_file:
		line = line.strip()
		print line
	input_file.close()

if __name__ == "__main__":
	process_file(sys.argv[1])
