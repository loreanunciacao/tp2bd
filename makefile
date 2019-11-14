all: upload
		./upload $(data) && rm -rf upload

upload: 
		g++ -Wall scr/upload.cpp scr/support/parser.cpp scr/support/hashFile.cpp -o upload

		
