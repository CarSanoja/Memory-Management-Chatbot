#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
#include <iostream>

GraphNode::GraphNode(int id) {
    _id = id;
}

GraphNode::~GraphNode() {
    //// STUDENT CODE
    ////

    // this was deleted to quit the initial bug, it does not make sense
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) {
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
    _parentEdges.push_back(edge);
}
//as the child node now is a smart pointer, in order to prsed it the definition is changed
void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
// parsing the objetc as a R reference
void GraphNode::MoveChatbotHere(ChatBot chatBot) {
    _chatBot = std::move(chatBot);
    // update the chatLogic
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot); 
    // for some reason the operator -> give some build troubles
    // as an object it was changed to properly compile
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
    //// STUDENT CODE
    ////
    // to get the value from the smart pointer .get is neded
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}