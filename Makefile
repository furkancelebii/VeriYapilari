basla: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/KonsoldaGoster.o -c ./src/KonsoldaGoster.cpp
	g++ -I ./include/ -o ./lib/OkuEkle.o -c ./src/OkuEkle.cpp
	g++ -I ./include/ -o ./lib/Yonetici.o -c ./src/Yonetici.cpp
	g++ -I ./include/ -o ./lib/YoneticiDugum.o -c ./src/YoneticiDugum.cpp
	g++ -I ./include/ -o ./lib/Satir.o -c ./src/Satir.cpp
	g++ -I ./include/ -o ./lib/SatirDugum.o -c ./src/SatirDugum.cpp

	g++ -I ./include/ -o ./bin/main ./lib/KonsoldaGoster.o ./lib/YoneticiDugum.o ./lib/Satir.o ./lib/SatirDugum.o ./lib/Yonetici.o  ./lib/OkuEkle.o   ./src/main.cpp
	
calistirma:
	./bin/main