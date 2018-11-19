#include <iostream>
#include <cstring>

struct flex_array_t
{
    double * a_values;
    std::size_t capacity;
    int quantity;
};

void print_flex(flex_array_t const & to_print);
void print_flex(flex_array_t const & to_print)
{
  for (std::size_t index_print{0}; index_print < to_print.quantity; index_print++)
  {
    std::cout << to_print.a_values[index_print] << " ";
  }
  std::cout << std::endl;

  std::cout << "current capacity: " << to_print.capacity << std::endl;
}

flex_array_t init_flex();
flex_array_t init_flex()
{
  flex_array_t new_flex;

  new_flex.a_values = new double[3];
  new_flex.capacity = 3;
  new_flex.quantity = 0;

  return new_flex;
}

void dealloc_flex(flex_array_t & to_dealloc);
void dealloc_flex(flex_array_t & to_dealloc)
{
  delete [] to_dealloc.a_values;
  to_dealloc.a_values = nullptr;
  to_dealloc.capacity = 0;
  to_dealloc.quantity = 0;
}

void append_elements(flex_array_t & to_append, double to_add[], int num_add);
void append_elements(flex_array_t & to_append, double to_add[], int num_add)
{
  // check if size needs to be increased
  if (to_append.quantity + num_add > to_append.capacity)
  {
    // calculate how many total elements we need
    int new_capacity = ((to_append.quantity + num_add) / 3 + 1) * 3;

    // allocate a new array
    double * p_new{new double[new_capacity]};

    // copy old elements to new array
    for (std::size_t index_old{0}; index_old < to_append.quantity; index_old++)
    {
      p_new[index_old] = to_append.a_values[index_old];
    }

    // transfer from to_add to to_append
    for (int index_new = 0; index_new < num_add; index_new++)
    {
      p_new[index_new + to_append.quantity] = to_add[index_new];
    }

    // deallocate old array
    delete [] to_append.a_values;

    // point a_values to new array
    to_append.a_values = p_new;

    // update capacity
    to_append.capacity = new_capacity;

    // update quantity
    to_append.quantity += num_add;
  }
  else
  {
    // transfer from to_add to to_append
    for (int index_new = 0; index_new < num_add; index_new++)
    {
      to_append.a_values[index_new + to_append.quantity] = to_add[index_new];
    }
  }
}

int main();
int main()
{
    flex_array_t speeds = init_flex();

    print_flex(speeds);

    const int new_quantity_1{2};
    double add_elements_1[new_quantity_1]{62.3, 63.0};
    append_elements(speeds, add_elements_1, new_quantity_1);

    print_flex(speeds);

    const int new_quantity_2{5};
    double add_elements_2[new_quantity_2]{64.9, 64.5, 64.1, 63.8, 63.0};
    append_elements(speeds, add_elements_2, new_quantity_2);

    print_flex(speeds);

    dealloc_flex(speeds);

    print_flex(speeds);

    return 0;
}
