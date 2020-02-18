all: bellmanford dijkstra kruskal prim

bellmanford: ./bellman-ford/bellmanford.cpp
	g++ ./bellman-ford/bellmanford.cpp -o bellmanford

dijkstra: ./dijkstra/dijkstra.cpp
	g++ ./dijkstra/dijkstra.cpp -o dijkstra
	
kruskal: ./kruskal/kruskal.cpp
	g++ ./kruskal/kruskal.cpp -o kruskal
	
prim: ./prim/prim.cpp
	g++ ./prim/prim.cpp -o prim
	
run:
	bellmanford.exe < ./bellman-ford/in.txt > ./bellman-ford/out.txt
	dijkstra.exe < ./dijkstra/in.txt > ./dijkstra/out.txt
	kruskal.exe < ./kruskal/in.txt > ./kruskal/out.txt
	prim.exe < ./prim/in.txt > ./prim/out.txt