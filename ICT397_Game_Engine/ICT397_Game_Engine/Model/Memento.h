#ifndef MEMENTO_H
#define MEMENTO_H
#include <string>

using namespace std;

class Memento
{
private:
    friend class Originator;

	/**
        * @brief Default constructor of class Memento
        *
        * This constructor sets the variables of class Memento to the default
        * values
        *
		* @param const string& state
        */
    Memento(const string& state);

	/**
        * @brief Destructor of class Memento
        *
        * This destructor frees memory from the Memento instance _state
        *
        */
    ~Memento();

	/**
        * @brief Stores the current state
        *
        * This function stores the current state as a read-only string
        *
		* @param const string& state
		* @return void
        */
    void SetState(const string& state);

	/**
        * @brief Returns a stored state
        *
        * This function returns a stored state from a read-only string
        *
		* @return string
        */
    string GetState();

    string _state;
};

class Originator
{
public:
	/**
        * @brief Default constructor of class Originator
        *
        * This constructor sets the variables of class Originator to the default
        * values
        *
        */
    Originator();

	/**
        * @brief Parameterised constructor of class Originator
        *
        * This constructor sets the variables of class Originator to the default
        * values
        *
		* @param const string& state
        */
    Originator(const string& state);

	/**
        * @brief Destructor of class Originator
        *
        * This destructor frees memory from the Originator instance _state
        *
        */
    ~Originator();

	/**
        * @brief Stores the current Memento's state
        *
        * This function stores the current Memento instance _state 
        *
		* @param Memento* pMemento
		* @return void
        */
    void RestoreToMemento(Memento* pMemento);

	/**
        * @brief Returns a Memento's state
        *
        * This function returns a Memento instance _state
        *
		* @return Memento*
        */
    Memento* CreateMemento();

	/**
        * @brief Stores the current state
        *
        * This function stores the current state as a read-only string
        *
		* @param const string& state
		* @return void
        */
    void SetState(const string& state);

	/**
        * @brief Returns a stored state
        *
        * This function returns a stored state from a read-only string
        *
		* @return string
        */
    string GetState();

	/**
        * @brief Outputs the current state
        *
        * This function outputs the current state to the command box
        *
		* @return void
        */
    void show();
protected:
private:
    string _state;
};

class Caretaker
{
public:
	/**
        * @brief Default constructor of class Caretaker
        *
        * This constructor sets the variables of class Caretaker to the default
        * values
        *
        */
    Caretaker();

	/**
        * @brief Destructor of class Originator
        *
        * This destructor frees memory from the Caretaker instance _memento
        *
        */
    ~Caretaker();

	/**
        * @brief Stores the current Memento's state
        *
        * This function stores the current Memento instance
        *
		* @param Memento*
		* @return void
        */
    void SetMemento(Memento*);

	/**
        * @brief Returns a Memento's state
        *
        * This function returns a Memento instance
        *
		* @return Memento*
        */
    Memento* GetMemento();
private:
    Memento* _memento;
};

#endif