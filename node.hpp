#ifndef NODE_H_
#define NODE_H_

#include <string>
class node {
	private:
		std::string userID;
		std::string password;
		node* next;

	public:
		node();
		node(node* n);
		~node();
		std::string getID();
		std::string getPass();
		node* getNext();
		void setID(std::string i);
		void setPass(std::string p);
		void setNext(node* n);
};

#endif 
