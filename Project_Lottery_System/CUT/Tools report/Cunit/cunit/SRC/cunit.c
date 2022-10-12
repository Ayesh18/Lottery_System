#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "CUnit/Basic.h"
#include <ctype.h>
#include "func.h"
#include "init.h"
#include "tests.h"
int main()
{
        CU_pSuite pSuite1 = NULL;
        CU_pSuite pSuite2 = NULL;
        CU_pSuite pSuite3 = NULL;

        if (CUE_SUCCESS != CU_initialize_registry())
        {
                return CU_get_error();
        }

        pSuite1 = CU_add_suite("suite for add participant data...", init_suite_add_participant_to_list, clean_suite_add_participant_to_list);

        if (NULL == pSuite1)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        pSuite2 = CU_add_suite("suite for remove participant data...", init_suite_remove_participant_from_list, clean_suite_remove_participant_from_list);

        if (NULL == pSuite2)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        pSuite3 = CU_add_suite("suite for add plot data...", init_suite_add_plot_to_list, clean_suite_add_plot_to_list);

        if (NULL == pSuite3)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite1, "Test for add_participant_to_list() in sunny cases", add_participant_to_list_sunnycases)) || (NULL == CU_add_test(pSuite1, "Test for add_participant_to_list() in rainy cases", add_participant_to_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite2, "Test for remove_participant_from_list() in sunny cases", remove_participant_from_list_sunnycases)) || (NULL == CU_add_test(pSuite2, "Test for remove_participant_from_list() in rainy cases", remove_participant_from_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite3, "Test for add_plot_to_list() in sunny cases", add_plot_to_list_sunnycases)) || (NULL == CU_add_test(pSuite3, "Test for add_plot_to_list() in rainy cases", add_plot_to_list_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
