all:p2p_dgrm.o p2p_txbuf.o p2p_rdt.o

p2p_dgrm.o:
	g++ -c p2p_dgrm.cpp -I/opt/json/include
p2p_txbuf.o:
	g++ -c p2p_txbuf.cpp -I/opt/json/include
p2p_rdt.o:
	g++ -c p2p_rdt.cpp -I/opt/json/include
clean:
	-rm *.o