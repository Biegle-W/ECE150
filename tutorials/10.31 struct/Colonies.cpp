marking scheme:

// we don't need to write the struct, as it was given
// we don't need to write a main() function, as it was not asked for

// first thing to recognize is that the initial colony populations are inputted
// into the function through the colonies[] array; and that the output of the
// function is that same colonies array (arrays are always passed-by-reference)

void simulate_marmosets(marmoset_colony colonies[],
    int num_colonies,
    int num_years)
{
    const double FEMALE_RATE = 0.32;
    const double MALE_RATE_1 = 0.29;
    const double MALE_RATE_2 = 0.27;
    const int MALE_LIMIT = 100;

    // 1 mark for outer loop that loops for the given number of years
    for (int year = 0; year < num_years; year++)
    {
        // 1 mark for starting the colony_index at 0
        // 1 mark for ending the colony_index at (num_colonies - 1)
        for (int colony_index = 0; colony_index < num_colonies; colony_index++)
        {
            int num_pairs{0};
            int new_females{0};
            int new_males{0};

            // 1 mark for accessing the colonies[colony_index] element, and the
            // qty_females and qty_males elements of the struct
            // 1 mark for calculating the number of pairs; minimum of qty_females
            // and qty_males
            if (colonies[colony_index].qty_females < colonies[colony_index].qty_males)
                num_pairs = colonies[colony_index].qty_females;
            else
                num_pairs = colonies[colony_index].qty_males;

            // 1 mark for calculating the number of new females, using integer arithmetic
            new_females = num_pairs * FEMALE_RATE;
            // 1 mark for checking number of males and using the appropriate rate
            if (colonies[colony_index].qty_males <= MALE_LIMIT)
                new_males = num_pairs * MALE_RATE_1;
            else
                new_males = num_pairs * MALE_RATE_2;

            // 1 mark for updating the colonies array with the new marmosets
            colonies[colony_index].qty_females += new_females;
            colonies[colony_index].qty_males += new_males;
        }
    }

    // -1 for return statement
}

// take mark out of 8 and divide by 2 to get an approximate mark for the exam

// optional test code
int main()
{
    const int NUM_UW_COLONIES = 3;
    marmoset_colony UW_colonies[NUM_UW_COLONIES]
        {{19, 13}, {78, 103}, {67, 67}};

    simulate_marmosets(UW_colonies, NUM_UW_COLONIES, 5);
}
