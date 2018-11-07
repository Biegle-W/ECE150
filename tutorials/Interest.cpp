marking scheme:

// we don't need to write the struct, as it was given
// we don't need to write a main() function, as it was not asked for
void monthly_interest(float interest_paid[],
    bank_account accounts[],
    int num_accounts)
{
    const double CHECK_RATE = 0.00375;
    const double SAV_RATE_1 = 0.00589;
    const double SAV_RATE_2 = 0.00425;
    const double MIN_SAVINGS = 5000;

    // 1 mark for loop starting at index 0
    // 1 mark for loop ending at index (num_accounts - 1)
    for (int account_index = 0;
         account_index < num_accounts;
         account_index++)
    {
        // 1 mark for overwriting the initial interest_paid array value
        // 1 mark for accessing the individual element of accounts, and the checking element
        // 1 mark for multiplying by 0.00375 (not 0.375)
        interest_paid[account_index] = accounts[account_index].checking * CHECK_RATE;

        // 1 mark for if statement accessing individual element of accounts, and the
        // savings elements, and comparing it with 5000
        if (accounts[account_index].savings > MIN_SAVINGS)
            // 1 mark for multiplying by 0.00589 if greater than 5000 and 0.00425
            // if less than 5000
            // 1 mark for accessing the interest_paid array and adding to its value
            interest_paid[account_index] += accounts[account_index].savings * SAV_RATE_1;
        else
            interest_paid[account_index] += accounts[account_index].savings * SAV_RATE_2;
    }

    // -1 mark if there is a return statement
}

// take mark out of 8 and divide by 2 to get an approximate mark for the exam
