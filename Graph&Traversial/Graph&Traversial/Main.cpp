#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <utility>



#define NULLEDGE 0


template<class vtype, class etype>
class GraphV2 {
public:
	std::map<vtype, std::list<std::pair<vtype, etype>>> edges;
	GraphV2() {
		edges = std::map<vtype, std::list<std::pair<vtype, etype>>>();
	}
	bool vExists(vtype vertex) {
		return (edges.find(vertex) != edges.end());
	}

	bool addVertex(vtype vertex) {
		if (!vExists(vertex)) {
			edges[vertex];
			return true;
		}
		return false;
	}
	bool removeVertex(vtype vertex) {
		if (vExists(vertex)) {
			edges.erase(vertex);
			for (auto& v = edges.begin(); v != edges.end(); ++v) {
				for (auto& connection : v.second) {
					v.second.remove_if(connection.first == vertex);
				}
			}
		}
	}
	bool addEdge_veq1(vtype fromV, vtype toV) {
		return eddEdge(fromV, toV, 1);
	}
	bool eddEdge(vtype fromV, vtype toV, etype connection_weight) {
		if (vExists(fromV) && vExists(toV)) {
			std::pair<vtype, etype> connection(toV, connection_weight);
			edges[fromV].push_back(connection);
			return true;
		}
		return false;
	}
};

class Graph {
public:
	int** edges;
	bool* visited;
	int v;
	Graph(int v) {
		edges = new int*[v];
		visited = new bool[v];
		this->v = v;
		for (int i = 0; i < v; i++) {
			edges[i] = new int[v];
			for (int j = 0; j < v; j++) {
				edges[i][j] = NULLEDGE;
			}
		}

	}
	void clearMarks() {
		for (int i = 0; i < v; i++) {
			visited[i] = false;
		}
	}
	void addEdge_val_eq_1(int from, int to) {
		addEdge(from, to, 1);
	}
	void addEdge(int from, int to, int connection_value) {
		edges[from][to] = connection_value;
	}
	bool fullyConnected() {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (i != j) {
					if (!DFS(i, j)) { return false; }
				}
			}
		}
		return true;
	}

	bool DFS(int start, int end) {
		std::stack<int> st = std::stack<int>();
		clearMarks();
		visited[start] = true;
		st.push(start);
		while (!st.empty()) {
			int curr_vertex = st.top(); st.pop();
			std::cout << curr_vertex << std::endl;
			if (curr_vertex == end) {
				std::cout << std::endl;

				return true;
			}
			for (int i = 0; i < v; i++) {
				if (edges[curr_vertex][i] != NULLEDGE) {
					if (!visited[i]) {
						visited[i] = true;
						st.push(i);
					}
				}
			}
		}
		return false;
	}

	bool BFS(int start, int end) {
		std::queue<int> Q = std::queue<int>();
		clearMarks();
		visited[start] = true;
		Q.push(start);
		while (!Q.empty()) {
			int curr_vertex = Q.front(); Q.pop();
			std::cout << curr_vertex << std::endl;
			if (curr_vertex == end) {
				std::cout << std::endl;

				return true;
			}
			for (int i = 0; i < v; i++) {
				if (edges[curr_vertex][i] != NULLEDGE) {
					if (!visited[i]) {
						visited[i] = true;
						Q.push(i);
					}
				}
			}
		}
		return false;
	}

	int** get_transitive_closure() {
		int** transitive_closure = new int* [v];
		for (int i = 0; i < v; i++) {
			transitive_closure[i] = new int[v];
			for (int j = 0; j < v; j++) {
				if (DFS(i, j)) {
					transitive_closure[i][j] = 1;
				}
				else {
					transitive_closure[i][j] = 0;
				}
			}
		}
		return transitive_closure;
	}
	void print_transitive_closure() {
		int** transitive_closure = get_transitive_closure();
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				std::cout << transitive_closure[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	
	std::pair<int*, int*> dijkstra(int start) {
		int* cost = new int[v];
		int* previous = new int[v];
		for (int i = 0; i < v; i++) {
			cost[i] = INT_MAX;
			previous[i] = -1;
		}
		clearMarks();
		cost[start] = 0;
		visited[start] = true;
		//			std::greater<std::pair<int, int> by default prioritezes the first element to the pair using minHeap
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
		pq.push({ 0, start });
		while (!pq.empty()) {
			std::pair<int, int> vertex = pq.top(); pq.pop();
			visited[vertex.second] = true;
			for (int i = 0; i < v; i++) {
				if (!visited[i] && edges[vertex.second][i] != NULLEDGE) {
						int new_cost = edges[vertex.second][i] + cost[vertex.second];
						if (new_cost < cost[i]) {
							pq.push({ new_cost, i });
							cost[i] = new_cost;
							previous[i] = vertex.second;
						}
				}
				
			}
		}
		return std::pair<int*, int*>(cost, previous);
	}


	Graph minimal_spanning_tree() {
		Graph minTree(this->v);
		int cost = 0, v_count = 0;
		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;
		clearMarks();
		for (int i = 0; i < v;i++) {
			for (int j = 0; j < v;j++) {
				if(edges[i][j] != NULLEDGE){
					pq.push(std::pair<int, std::pair<int, int>>(edges[i][j], std::pair<int, int>(i, j)));
				}
			}
		}
		while (v_count < v - 1) {
			std::pair<int, std::pair<int, int>> minEdge = pq.top(); pq.pop();
			if (!(visited[minEdge.second.first] && visited[minEdge.second.second])) {
				v_count++;
				cost += minEdge.first;
				minTree.addEdge(minEdge.second.first, minEdge.second.second, minEdge.first);
				visited[minEdge.second.first] = true; visited[minEdge.second.second] = true;
			}

		}
		std::cout << "Tree Cost = " << cost << std::endl;
		return minTree;
	}
};


std::pair<int*, int> minChange(int* coins, int n, int number) {
	int* chosen = new int[n], coincount = 0;

	for (int i = 0; i < n; i++) {
		chosen[i] = 0;
	}
	for (int i = 0; i < n;) {
		if (number >= coins[i]) {
			number -= coins[i];
			coincount++;
			chosen[i]++;
		}
		else { i++; }
	}
	return std::pair<int*, int>(chosen, coincount);
}

bool itemGreater(std::pair<int, int> first, std::pair<int, int>second){
	double val1 = (double)first.first / (double)first.second;
	double val2 = (double)second.first / (double)second.second;
	return val1 > val2;
}
std::pair<int*, int> knapsack(std::pair<int, int>* items, int n, int weightCap) {
	int* chosen = new int[n], itemsvalue = 0;

	for (int i = 0; i < n; i++) {
		chosen[i] = 0;
	}
	
	std::sort(items, items + n, itemGreater);

	for (int i = 0; i < n; i++) {
		std::cout << items[i].first << "  " << items[i].second << std::endl;
		if (weightCap >= items[i].second) {
			weightCap -= items[i].second;
			itemsvalue += items[i].first;
			chosen[i]++;
		}
		
	}

	return std::pair<int*, int>(chosen, itemsvalue);
}



void run() {
	int Vs = 5;
	Graph g = Graph(Vs);
	g.addEdge(0, 1, 120);
	g.addEdge(0, 3, 6);

	g.addEdge(1, 3, 8);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 1, 3);
	g.addEdge(2, 4, 100);
	g.addEdge(3, 0, 6);
	g.addEdge(3, 2, 5);

	g.addEdge(4, 1, 5);
	g.addEdge(4, 2, 7);
	g.addEdge(4, 3, 9);

	std::pair<int*, int*> dijkstra_result = g.dijkstra(0);


	int i = 4;
	std::cout << " Cost: " << dijkstra_result.first[i] << ". Rout:  ";

	std::cout << i << " <- ";

	 do{
		std::cout << dijkstra_result.second[i] << " <- ";
		i = dijkstra_result.second[i];
	}while (i != 0);
	std::cin.get();
	Graph spaningTree = g.minimal_spanning_tree();
	for (int i = 0; i < Vs; i++) {
		for (int j = 0; j < Vs; j++) {
			std::cout << spaningTree.edges[i][j] << " ";
		}
		std::cout << std::endl;
	}
}





int main() {

	std::pair<int, int> items[] = { std::pair<int, int>(10, 5),
								   std::pair<int, int>(20, 7),
								   std::pair<int, int>(30, 10),
								   std::pair<int, int>(40, 14),
								   std::pair<int, int>(50, 18),
								   std::pair<int, int>(60, 22),
								   std::pair<int, int>(70, 26) };


	std::pair<int*, int> knapsack_res = knapsack(items, 7, 100);
	for (int i = 0; i < 7; i++) {
		std::cout << knapsack_res.first[i] << std::endl;
	}
	std::cout << knapsack_res.second << std::endl;

}