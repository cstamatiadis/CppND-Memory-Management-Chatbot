#include <iostream>
#include <memory.h>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
GraphNode::GraphNode(const GraphNode &node)
 {
     std::cout << "COPYING content of instance " << &node << " to instane " << this << std::endl;

     for (auto it = std::begin(node._childEdges); it != std::end(node._childEdges); ++it)
     {
         GraphEdge childEdge = *(*it);
         _childEdges.push_back(std::move(std::make_unique<GraphEdge> (childEdge.GetID())));
     }

     for (auto it = std::begin(node._parentEdges); it != std::end(node._parentEdges); ++it)
     {
         _parentEdges.push_back(std::move(*it));
     }

     _chatBot = node._chatBot;
     _id = node._id;

     for (auto it = std::begin(node._answers); it != std::end(node._answers); ++it)
     {
         std::string answer = *it;
         _answers.push_back(answer);
     }
 }

 GraphNode & GraphNode::operator=(const GraphNode &node)
 {
     std::cout << "ASSIGNING content of instance " << &node << " to instane " << this << std::endl;

     if (this == &node)
         return *this;

     for (auto it = std::begin(node._childEdges); it != std::end(node._childEdges); ++it)
     {
         GraphEdge childEdge = *(*it);
         _childEdges.push_back(std::move(std::make_unique<GraphEdge> (childEdge.GetID())));
     }

     for (auto it = std::begin(node._parentEdges); it != std::end(node._parentEdges); ++it)
     {
         _parentEdges.push_back(*it);
     }

     _chatBot = node._chatBot;
     _id = node._id;

     for (auto it = std::begin(node._answers); it != std::end(node._answers); ++it)
     {
         std::string answer = *it;
         _answers.push_back(answer);
     }

     return *this;
 }

 GraphNode::GraphNode(GraphNode &&node)
 {
     std::cout << "MOVING (constructor) content of instance " << &node << " to instane " << this << std::endl;

     for (auto it = std::begin(node._childEdges); it != std::end(node._childEdges); ++it)
     {
         _childEdges.push_back(std::move(*it));
     }

     for (auto it = std::begin(node._parentEdges); it != std::end(node._parentEdges); ++it)
     {
         _parentEdges.push_back(*it);
     }

     _id = node._id;

     for (auto it = std::begin(node._answers); it != std::end(node._answers); ++it)
     {
         _answers.push_back(*it);
     }

     _chatBot = std::move(node._chatBot);
     node._childEdges.clear();
     node._parentEdges.clear();
     node._id = 0;
     node._answers.clear();
 }

 GraphNode & GraphNode::operator=(GraphNode &&node)
 {
     std::cout << "MOVING (assignment) content of instance " << &node << " to instane " << this << std::endl;

     if (this == &node)
         return *this;

     _childEdges.clear();
     _parentEdges.clear();
     _answers.clear();

     for (auto it = std::begin(node._childEdges); it != std::end(node._childEdges); ++it)
     {
         _childEdges.push_back(std::move(*it));
     }

     for (auto it = std::begin(node._parentEdges); it != std::end(node._parentEdges); ++it)
     {
         _parentEdges.push_back(*it);
     }

     _id = node._id;

     for (auto it = std::begin(node._answers); it != std::end(node._answers); ++it)
     {
         _answers.push_back(*it);
     }

     _chatBot = std::move(node._chatBot);
     node._childEdges.clear();
     node._parentEdges.clear();
     node._id = 0;
     node._answers.clear();

     return *this;
 }
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}