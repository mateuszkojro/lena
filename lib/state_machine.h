#ifndef PARSER_H
#define PARSER_H
#include <iostream>

template <class> class state_interface;
template <class t> class state_machine; 


template <class t> class state_machine {
public:
  state_interface<t> current_state_;
  t target_obj_;
  inline void change_state(state_interface<t> *new_state) {current_state_ = new_state;};
  inline t get() {return target_obj_;};
  virtual ~state_machine<t>(){};
};

template <class t> class state_interface {
public:
  inline virtual void read(char, state_machine<t> *) {printf("kurwaaa");};
protected:
  virtual ~state_interface(){} 
};

#endif