/*
Graph Theory
	A graph is an abstraction where you have a set of V of vertices and E edgers {V1,V2}
	If a graph is connected
		can reach a node from any other node
		From any vertex you can reach any other node
	Bi-Connected
		No single edge which is a point of failure
		Cutting one edge does not destroy the path/linkage
	Complete Graph
		Each vertice is connected to everyone else
			To connect them all
			(v-1) +(v-2) + ... + 1
			V(V-1)/2 = O(V^2)
			Smallest one is 0 edges needed or 1V
	Directed Graph: DiGraph
		Have weights and arrows
		Going one way
	Cycle
		A loop existing
	Tree
		Each branch never rejoins others
		DAG
			This is a special case where they do rejoing but head 1 direction
	Path is a finite or infinite sequence of vertices
	Tour:?

	Representation (Only allowed to use V and E during BIG-O questions )
		1.List of every vertex and List of every edge (stupid, no need to store vertices and edge is O(v^2)
		2.Array of vertices and each node is a linked list to all vertices on who that is connected to, best case is V
			Very good when most edges are not there
		3. Matrix with row being from and to be column, O(1) time to tell if vertex K is adjacent to vertex m
			Space complexity O(E) = O(V^2) omega(V^2) so theta = V^2
			Can represent an array with weights, can't use 0 tho must use infinity as default value
			Negative Cycle can lead to loops
		4. EdgeList Representation with weights is vertex to 1 holding weight which holds a container to do next vertex

	Seven Major Algorithms


	Depth First Search(DFS)(recursive and iterative) / Breadth First Search(iteratively)
		Depth is when you visit somebody you keep going
		Breadth is you do your node first and then keep going
			Need data structure to keep track on where you've been
			O(V^2) worst case

			DFS Recursive
				g.DFS(v) //object called a g which is a graph
					visited <- [false,false,false...] //O(V)
						g.DFS2(v, visited)
					end

				g.DFS2(v, visited)
					visited[v] <- true; //every time you do it, you are marking 1 off
					print v
					for each v2 in adjacent(v) //for matrix O(v), for linkedlist O(v) or omega(1)
						if NOT visited[v2]
							g.DFS2(v2,visited) //depth of stack is limited to how many vertices you can have
						end
					end
				end
				This is all V^2 due to you checking V paths and marking a V off

			DFS Iterative
				g.DFS(v)
					visited <- [false,false...]
					stack <- empty;
					stack.push(v)
					visited[v] <- true
					while NOT stack.empty()
						V<-stack.pop()
						print v
						for each v2 in adjacent(v)
						 if NOT visited[v2]
							visited[v2] <- true
							stack.push(v2) //need to push in order either numerically or alphabettically
						end
					end
				end
			end//Matrix always has this taking v


			Breadth First Search(like ripples in a pond)
			g.BFS(v)
				visited<-[]
				queue<-empty
				queue.enqueue(v)
				visited[v] <- true
				while NOTE queue.empty()
					v <- queue.dequeue();
					print v
					for each v2 in adjacent(v)
					//is same as DFS but enqueue and dequeue


			bool <- g.isConnected()//O(v^2)
				visited<-g.DFS(r) //O(v^2)
				for i<-0 to V
					if NOT visited[i]
						return false
					end
				return true
			end

			Bellman-Ford (looks V^2 but ends up being V^3 due to recalculation)
				Least cost path from X to Y
				Need a single array of costs where they deafult to infinite first
				But current location costs you zero
				Need two arrays to know how, array 1 holds cost and array 2 holds where did you come From
				O(2V) storage = O(V) time = O(VE) or O(V^2)

				BellmanFord(start, end) //can give either a do it question or a code
				cost <- [inf,inf...]
				cost[start] = 0
				for v=0 to V-1
					for each edge e from v
						if cost[v2]>cost[v] + adjacent[v2]

						LOOK BACK FOR THIS


				Floyd Wallshal? //will not give a Floyd to do as matrix but just compute
					dist <-|V| x |V| arrau of minimum distance initalized to inf
					for each vertex v
						dist[v][v] <- 0
					for each edge
						//some shit happens

					for k from 1 to |v|
						for i from 1 to |V|
							for j from 1 to |v|
								if dist[i][j] > dist[i][k] + dist[k][j]
									dist[i][j] <- dist[i][k] + dist[k][j]
								end
							end
						end
					end



				Minimum Spanning Tree
					How do you connect things via minimum cost
					This a greedy algorithm, can start with anyone you like

					Prim
						Pick an edge that is cheap as possible(random if tie) but pick one that you are not connected to yet
						Just know how to draw and do it by hand no code cause fucc that
						O(V)+ O(2V) + O(3V) + ...
							Brute Force: V^3
							Data Struct V^2LogV
					Kruskal
						Find the cheapest edge
						connect those two
						Find next cheapest edge
						Connect those two
							still don't want to connect ones already connected


					Travelling Salesman Problem (TSP)
						start at a vertex v, visit all vertices and return to the original V with minimum cost
						O(V!)
						Find optimal route to go out to visit everyone and come back
*/
