
/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include "MutablePriorityQueue.h"
#include "Local.h"
#include <cmath>
using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // outgoing edges
	bool visited;          // auxiliary field
	double dist = 0;
	Vertex<T> *path = nullptr;
	int queueIndex = 0;
public:
    int getQueueIndex() const;

    void setQueueIndex(int queueIndex);

private:
    // required by MutablePriorityQueue

	void addEdge(Vertex<T> *dest, double w);


public:
	Vertex(T in);

    Vertex(T info, int queueIndex);
    bool removeEdgeTo(Vertex<T> *d);
    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	T getInfo() const;
    const vector<Edge<T>> &getAdj() const;
	double getDist() const;
	Vertex *getPath() const;

    void setInfo(T info);

    bool isVisited() const;

    Edge<T> findEdge(T dest);
    friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template<class T>
Vertex<T>::Vertex(T info, int queueIndex):info(info), queueIndex(queueIndex) {}


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 *
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    int velocity;
    if(w>100)velocity=120;
    else velocity=50;
	adj.push_back(Edge<T>(this, d, w,velocity));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> *orig; 	// Fp07
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
    int velocity;
public:
    int getVelocity() const;

    void setVelocity(int velocity);

private:
    bool selected; // Fp07

public:
	Edge(Vertex<T> *o, Vertex<T> *d, double w);

    Edge(Vertex<T> *orig, Vertex<T> *dest, double weight, int velocity);

    friend class Graph<T>;
	friend class Vertex<T>;

	// Fp07
	double getWeight() const;

    Vertex<T> *getOrig() const;

    void setOrig(Vertex<T> *orig);

    Vertex<T> *getDest() const;

    void setDest(Vertex<T> *dest);

    void setWeight(double weight);
};

template <class T>
Edge<T>::Edge(Vertex<T> *o, Vertex<T> *d, double w): orig(o), dest(d), weight(w) {}

template <class T>
double Edge<T>::getWeight() const {
	return weight;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

	// Fp05
	Vertex<T> * initSingleSource(const T &orig);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	double ** W = nullptr;   // dist
	int **P = nullptr;   // path


public:
    int findVertexIdx(const T &in) const;
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(Local in);
    bool addVertex(const T &in,int index);
    bool removeVertex(const T &in);
    bool removeEdge(const T &sourc, const T &dest);


	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	//FP04 -DFS
    void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
    vector<T> dfs(T v) const;

	// Fp05 - single source
	void dijkstraShortestPath(const T &s);
	void unweightedShortestPath(const T &s);
	void bellmanFordShortestPath(const T &s);
	vector<T> getPath(const T &origin, const T &dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;
	double getpathtime(const T &origin, const T &dest)const;
	~Graph();

	// Fp07 - minimum spanning tree
    bool addBidirectionalEdge(const T &sourc, const T &dest, double w);
	vector<Vertex<T>*> calculatePrim();
	vector<Vertex<T>*> calculateKruskal();



	//for the project
    void getGrafoConexo(Graph<T> & graph);
    double calcEdgeWeight(const T & sourc, const T & dest);

    void setW(double **w);

    double **getW() const;

    int **getP() const;

    void setP(int **p);

    int findLocalId(int id);

    T findLocal(int id);

    double set(const T &orig, const T &dest) const;
};

template<class T>
void Vertex<T>::setInfo(T info) {
    Vertex::info = info;
}

template<class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template<class T>
int Vertex<T>::getQueueIndex() const {
    return queueIndex;
}

template<class T>
void Vertex<T>::setQueueIndex(int queueIndex) {
    Vertex::queueIndex = queueIndex;
}

template<class T>
Edge<T> Vertex<T>::findEdge(T dest) {

    for(auto e:adj){
        if(e.dest->getInfo()==dest)return e;
    }
    return Edge<T>(nullptr, nullptr, 0);
}

template<class T>
Vertex<T> *Edge<T>::getOrig() const {
    return orig;
}

template<class T>
void Edge<T>::setOrig(Vertex<T> *orig) {
    Edge::orig = orig;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *dest) {
    Edge::dest = dest;
}

template<class T>
void Edge<T>::setWeight(double weight) {
    Edge::weight = weight;
}

template<class T>
int Edge<T>::getVelocity() const {
    return velocity;
}

template<class T>
void Edge<T>::setVelocity(int velocity) {
    Edge::velocity = velocity;
}

template<class T>
Edge<T>::Edge(Vertex<T> *orig, Vertex<T> *dest, double weight, int velocity):orig(orig), dest(dest), weight(weight),
                                                                             velocity(velocity) {}


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
template <class T>
int Graph<T>::findVertexIdx(const T &in) const {
	for (unsigned i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == in)
			return i;
	return -1;
}



template<class T>
int Graph<T>::findLocalId(int id) {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getInfo().getId() ==id)
            return i;
    return -1;
}


template<class T>
T Graph<T>::findLocal(int id) {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->info.getId()== id)
            return vertexSet[i]->info;
    return Local(-1);
}


/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(Local in) {
	if (findVertex(in) != nullptr)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

template <class T>
bool Graph<T>::addVertex(const T &in,int index) {
    if (findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex<T>(in,index));
    return true;
}



/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == nullptr || v2 == nullptr)
		return false;
	v1->addEdge(v2, w);
	return true;
}





/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    // TODO (5 lines)
    // HINT: Use "findVertex" to obtain the actual vertices.
    // HINT: Use the next function to actually remove the edge.
    auto s=findVertex(sourc);
    auto d=findVertex(dest);
    if(s!=NULL&&d!=NULL)return s->removeEdgeTo(d);
    return false;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    // TODO (6 lines)
    // HINT: use an iterator to scan the "adj" vector and then erase the edge.
    auto it=adj.begin();
    while(it!=adj.end()){
        if(it->dest==d){
            adj.erase(it);
            return true;
        }
        it++;
    }
    return false;
}


/****************** 1d) removeVertex ********************/

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}





/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for(auto v : vertexSet) {
		v->dist = INF;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	}
	else
		return false;
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
	q.insert(s);
	while( ! q.empty() ) {
		auto v = q.extractMin();
		for(auto e : v->adj) {
			auto oldDist = e.dest->dist;
			if (relax(v, e.dest, e.weight)) {
				if (oldDist == INF)
					q.insert(e.dest);
				else
					q.decreaseKey(e.dest);
			}
		}
	}
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
		return res;
	for ( ; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	auto s = initSingleSource(orig);
	queue< Vertex<T>* > q;
	q.push(s);
	while( ! q.empty() ) {
		auto v = q.front();
		q.pop();
		for(auto e: v->adj)
			if (relax(v, e.dest, 1))
				q.push(e.dest);
	}
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
	initSingleSource(orig);
	for (unsigned i = 1; i < vertexSet.size(); i++)
		for (auto v: vertexSet)
			for (auto e: v->adj)
				relax(v, e.dest, e.weight);
	for (auto v: vertexSet)
		for (auto e: v->adj)
			if (relax(v, e.dest, e.weight))
				cout << "Negative cycle!" << endl;
}


/**************** All Pairs Shortest Path  ***************/

template <class T>
void deleteMatrix(T **m, int n) {
	if (m != nullptr) {
		for (int i = 0; i < n; i++)
			if (m[i] != nullptr)
				delete [] m[i];
		delete [] m;
	}
}



template <class T>
Graph<T>::~Graph() {
	deleteMatrix(W, vertexSet.size());
	deleteMatrix(P, vertexSet.size());
}

template<class T>
void Graph<T>::floydWarshallShortestPath() {
	unsigned n = vertexSet.size();
	deleteMatrix(W, n);
	deleteMatrix(P, n);
	W = new double *[n];
	P = new int *[n];
	for (unsigned i = 0; i < n; i++) {
		W[i] = new double[n];
		P[i] = new int[n];
		for (unsigned j = 0; j < n; j++) {
			W[i][j] = i == j? 0 : INF;
			P[i][j] = -1;

		}

		for (auto e : vertexSet[i]->adj) {

			int j = findVertexIdx(e.dest->info);
			W[i][j]  = e.weight;
			P[i][j]  = i;

		}
	}

	for(unsigned k = 0; k < n; k++)
		for(unsigned i = 0; i < n; i++)
			for(unsigned j = 0; j < n; j++) {
				if(W[i][k] == INF || W[k][j] == INF)
					continue; // avoid overflow
				int val = W[i][k] + W[k][j];
				if (val < W[i][j]) {
					W[i][j] = val;
					P[i][j] = P[k][j];
                    //cout<<W[i][j]<<endl<<P[i][j]<<endl;
				}
			}
}


template<class T>
double Graph<T>::getpathtime(const T &origin, const T &dest) const {

    double time=0;
    unsigned o=findVertexIdx(origin);
    unsigned d=findVertexIdx(dest);
    auto partialdest=dest;
    if(o == -1 || d == -1 || W[o][d] == INF)return INF;
    while(o!=d){
        auto v=vertexSet[P[o][d]];
        auto e= v->findEdge(partialdest);
        time+=e.getWeight()/(e.getVelocity()*1000/60); //velocity is in km/h so its converted to m/min
        partialdest=v->getInfo();
        d=P[o][d];
    }
    return time;
}



template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	vector<T> res;
	int i = findVertexIdx(orig);
	int j = findVertexIdx(dest);
	if (i == -1 || j == -1 || W[i][j] == INF) // missing or disconnected
		return res;
	for ( ; j != -1; j = P[i][j])
		res.push_back(vertexSet[j]->info);
	reverse(res.begin(), res.end());
	return res;
}

template <class T>
vector<T> Graph<T>::dfs(T v) const {

    vector<T> res;
    for(auto it=vertexSet.begin();it<vertexSet.end();it++)(*it)->visited= false;
    dfsVisit(findVertex(v),res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
    v->visited=true;
    res.push_back(v->info);
    for(auto & e:v->adj){
        if(!e.dest->visited){
            dfsVisit(e.dest,res);
        }
    }
}


template<class T>
void Graph<T>::getGrafoConexo(Graph<T>& graph) {

    for (int i = 0; i < this->vertexSet.size(); i++) {
        if (vertexSet.at(i)->visited) {
            graph.addVertex(vertexSet.at(i)->info);
            for (auto &e:vertexSet[i]->adj) {
                if (e.dest->isVisited()) {
                    graph.addVertex(e.dest->info);
                    graph.addEdge(e.orig->info, e.dest->info, e.weight);
                }
            }
        }
    }

}






template<class T>
void Graph<T>::setW(double **w) {
    W = w;
}

template<class T>
double Graph<T>::calcEdgeWeight(const T &sourc, const T & dest) {
    auto s=findVertex(sourc);
    auto d=findVertex(dest);
    return s->getInfo().distance(d->getInfo());
}


template<class T>
double **Graph<T>::getW() const {
    return W;
}

template<class T>
int **Graph<T>::getP() const {
    return P;
}

template<class T>
void Graph<T>::setP(int **p) {
    P = p;
}



#endif /* GRAPH_H_ */

