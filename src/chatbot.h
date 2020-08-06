#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    //// the Rule of Five
    ////
    /*

    1. The destructor: Responsible for freeing the resource once the object it belongs 
    to goes out of scope. 

    2. The assignment operator: The default assignment operation 
    performs a member-wise shallow copy, which does not copy the content behind the 
    resource handle. If a deep copy is needed, it has be implemented by the programmer.

    3. The copy constructor: As with the assignment operator, the default copy constructor 
    performs a shallow copy of the data members. If something else is needed, the programmer 
    has to implement it accordingly.

    4. The move constructor: Because copying objects can be an expensive operation which 
    involves creating, copying and destroying temporary objects, rvalue references are 
    used to bind to an rvalue. Using this mechanism, the move constructor transfers the 
    ownership of a resource from a (temporary) rvalue object to a permanent lvalue object.

    5. The move assignment operator: With this operator, ownership of a resource can be 
    transferred from one object to another. 

    */
    ChatBot(const ChatBot & source);
    ChatBot &operator=(const ChatBot & source);
    ChatBot(ChatBot && source);
    ChatBot &operator=(ChatBot && source);
    ChatLogic * GetChatLogicHandle() {return _chatLogic;}
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */