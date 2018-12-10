#include <iostream>
#include <string>
#include "Message.h"


//Node constructor
Node::Node( unsigned int id, std::string frag):
identifier{id},
fragment{frag},
p_next{nullptr}{}

//Node public memeber functions
Node *Node::get_next()
{
    return p_next;
}

std::string Node::get_fragment()
{
    return fragment;
}

//Messsage constructor
Message::Message():
head{nullptr} {}

//Message distructor
Message::~Message()
{
    if (head!= nullptr)
    {
        Node *p_current{head};
        Node *p_delete{head};

        while (p_current->get_next() != nullptr)
        {
            p_delete = p_current;
            p_current = p_current->get_next();

            delete p_delete;
            p_delete = nullptr;
        }
        delete p_current;
        p_current = nullptr;
    }
}

//Message public member functions
void Message::insert(unsigned int id, std::string fragment)
{
    Node *p_new{new Node{id, fragment}};
    Node *p_current{head};

    if (head == nullptr || id == 0 || id < head->identifier) //  if the currrent linked list is empty, or if the message inserted is the first element, or if the message passed in is inserted in a position which is before the head
    {
        p_new->p_next = head;
        head = p_new;
    }
    else if (fragment == "EOT") // if the fragment passed in is "EOT"
    {
        for (; p_current->get_next() != nullptr; p_current = p_current->get_next())
        {
            // do nothing
        }
        p_current->p_next = p_new;
        p_new->p_next = nullptr;
    }
    else if (id > head->identifier) // if the message passed in is inserted in a posiiotn whihc is after the head
    {
        for (; p_current->p_next != nullptr && id > p_current->identifier; p_current = p_current->get_next())
        {
            if (id < p_current->get_next()->identifier)
            {
                p_new->p_next = p_current->get_next();
                p_current->p_next = p_new;
            }
        }
        if (p_current->p_next == nullptr)
        {
            p_current->p_next = p_new;
        }
    }
}

void Message::print_message()
{
    Node *p_current{head};
	Node *p_temp{head};
	Node *p_tail{head};
	std::size_t size{0};

	//get list size
	for (; p_tail->p_next != nullptr; p_tail = p_tail->get_next())
    {
        size++;
        //get to p_tail
    }

    //print the "???" before the first non-blank message
	if ((p_tail->get_fragment() != "EOT") && size == 0)
	{
		std::cout << "???";
	}
	else if (head->identifier == 0)
	{
		// do nothing
	}
	else
	{
		std::cout << "...";
		for (std::size_t i{1}; i < head->identifier; i++)
		{
			std::cout << " " << "...";
		}
	}

    //Begin to print message
	if (size != 0)
	{
		//print the first node
		if (head->identifier == 0 || head->fragment != "EOT") //1. print from the first message
		{
			if (head->fragment != "EOT")
			{
				std::cout << p_current->get_fragment();
			}
			if (p_current->get_next() != nullptr)
			{
				p_temp = p_current;
				p_current = p_current->get_next();
			}

		}
		else if (p_current ->fragment != "EOT") //2. the first message os blank, print after ...
		{
			std::cout << " " << p_current->get_fragment();
			p_temp = p_current;
			p_current = p_current->get_next();
		}

		while ((p_current != nullptr || p_current->fragment != "EOT") && p_current != head) //print everything between the first nod and EOT
		{
			if ((p_temp->identifier + 1) != p_current->identifier)
			{
				for (std::size_t i{p_temp->identifier + 1}; i < p_current->identifier; i++)
				{
					std::cout << " " << "...";
				}
			}

			if (p_current->fragment != "EOT")
			{
				std::cout << " " << p_current->get_fragment();
			}

			p_temp = p_current;
			p_current = p_current->get_next();

			if (p_current == nullptr)
			{
				break;
			}
		}

		if (p_tail->get_fragment() != "EOT") // if EOT haven't been transmitted, print ??? at the end
		{
			std::cout << " " << "???";
		}
	}

	std::cout << std::endl;
}


#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main()
{
    Message message;
    int input_id{-3};
    std::string input_frag;

    while (input_id != -2)
    {
        std::cin >> input_id;

        if (input_id >=0)
        {
            std::cin >> input_frag;
            message.insert(input_id, input_frag);
        }
        else if (input_id == -1)
        {
            message.print_message();
        }
    }

    return 0;
}
#endif
