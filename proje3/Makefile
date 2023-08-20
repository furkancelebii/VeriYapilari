basla: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/YukariListe.o -c ./src/YukariListe.cpp
	g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp
	g++ -I ./include/ -o ./lib/AsagiListe.o -c ./src/AsagiListe.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp

	g++ -I ./include/ -o ./bin/main ./lib/AsagiListe.o ./lib/YukariListe.o ./lib/Node.o ./lib/FileReader.o ./src/main.cpp
	
calistirma:
	./bin/main