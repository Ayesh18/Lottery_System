void add_participant_to_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(add_participant_to_list(1001,"Sai nath"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1002,"aaaaa"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1003,"bbbbb"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1004,"ccccc"),1);
        CU_ASSERT_EQUAL(add_participant_to_list(1005,"ddddd"),1);
}

void add_participant_to_list_rainycases(void)
{
        CU_ASSERT_EQUAL(add_participant_to_list(1006,"Sai"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1007,"aqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqa"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(123,"bbbbb"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1002,"ccccc"),0);
        CU_ASSERT_EQUAL(add_participant_to_list(1009,"ddd343d"),0);
}

void remove_participant_from_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(remove_participant_from_list(1001),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1002),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1003),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1004),1);
        CU_ASSERT_EQUAL(remove_participant_from_list(1005),1);
}
void remove_participant_from_list_rainycases(void)
{
        CU_ASSERT_EQUAL(remove_participant_from_list(1001),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1002),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1003),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1004),0);
        CU_ASSERT_EQUAL(remove_participant_from_list(1005),0);
}


void add_plot_to_list_sunnycases(void)
{
        CU_ASSERT_EQUAL(add_plot_to_list(1,1006,56789),1);
        CU_ASSERT_EQUAL(add_plot_to_list(2,1234,345678),1);
        CU_ASSERT_EQUAL(add_plot_to_list(25,4534,67896),1);
        CU_ASSERT_EQUAL(add_plot_to_list(45,3433,78789),1);
        CU_ASSERT_EQUAL(add_plot_to_list(98,4567,53453),1);
}

void add_plot_to_list_rainycases(void)
{
        CU_ASSERT_EQUAL(add_plot_to_list(1,1006,56789),0);
        CU_ASSERT_EQUAL(add_plot_to_list(101,1234,345678),0);
        CU_ASSERT_EQUAL(add_plot_to_list(88,4534,45000),0);
        CU_ASSERT_EQUAL(add_plot_to_list(35,87,78789),0);
        CU_ASSERT_EQUAL(add_plot_to_list(99,45678,53453),0);
}
