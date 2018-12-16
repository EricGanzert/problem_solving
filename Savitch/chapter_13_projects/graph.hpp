#ifndef GRAPH_H
#define GRAPH_H

namespace graph_eric
{
	struct GraphNode
	{
		char id;
		GraphNode* east;
		GraphNode* north;
		GraphNode* west;
		GraphNode* south;
	};
	typedef GraphNode* GraphNodePtr;

	void init_graph(); 

	void enter_maze();
}
#endif
