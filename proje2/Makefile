basla: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/DugumAgac.o -c ./src/DugumAgac.cpp
	g++ -I ./include/ -o ./lib/Yigin.o -c ./src/Yigin.cpp
	g++ -I ./include/ -o ./lib/BinaryBulma.o -c ./src/BinaryBulma.cpp


	g++ -I ./include/ -o ./bin/main ./lib/BinaryBulma.o ./lib/DugumAgac.o ./lib/Yigin.o ./src/main.cpp
	
calistirma:
	./bin/main