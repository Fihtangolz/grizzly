#ifndef GRIZZLY_VISITOR_H
#define GRIZZLY_VISITOR_H

void ast_visitor(const struct base_node_t* bn, void(*func)(struct base_node_t*));

#endif //GRIZZLY_VISITOR_H
