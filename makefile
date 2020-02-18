all: bellmanford dijkstra kruskal prim

bellmanford: ./Bellman-ford/bellmanford.cpp
	g++ ./Bellman-ford/bellmanford.cpp -o bellmanford

dijkstra: ./Dijkstra/dijkstra.cpp
	g++ ./Dijkstra/dijkstra.cpp -o dijkstra
	
kruskal: ./Kruskal/kruskal.cpp
	g++ ./Kruskal/kruskal.cpp -o kruskal
	
prim: ./Prim/prim.cpp
	g++ ./Prim/prim.cpp -o prim
	
run:	bellmanford dijkstra kruskal prim
	./bellmanford < ./Bellman-ford/in.txt > ./Bellman-ford/out.txt
	./dijkstra < ./Dijkstra/in.txt > ./Dijkstra/out.txt
	./kruskal < ./Kruskal/in.txt > ./Kruskal/out.txt
	./prim < ./Prim/in.txt > ./Prim/out.txt
