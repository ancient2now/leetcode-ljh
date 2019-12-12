#include "test.h"
#include "CUnit/Basic.h"
void array_print(int * array, int len);
int rand_array[max_size];
int sorted[max_size];
int comp(const void * a, const void * b){
    return *(int*)a-*(int*)b;
}
/*生成随机数组*/
void create_rand_array(){
    srand((unsigned)time(NULL));//srand()就是给rand()提供种子seed
    for (int i = 0; i < max_size; i++)
    {
        rand_array[i] = rand()%100;//对100取余操作
        sorted[i] = rand_array[i];
    }
    qsort(sorted, max_size, sizeof(int),comp);

}

static int suite_init(void)
{
    return 0;
}

static int suite_clean(void)
{
    return 0;
}

static void test_sort(void)
{
    create_rand_array();
    puts("");
    puts("初始数组:");
    array_print(rand_array, max_size);
    puts("有序数组:");
    array_print(sorted, max_size);

    /*bubble sort*/
    // BubbleSort(rand_array, max_size);
    // puts("冒泡排序后:");

    /*select sort*/
    // SelectSort(rand_array, max_size);
    // puts("选择排序后:");


    /*insert sort*/
    // InsertSort(rand_array, max_size);
    // puts("插入排序后:");

    /*shell sort*/
    // ShellSort(rand_array, max_size);
    // puts("希尔排序后:");

    /*quick sort*/
    QuickSort(rand_array, max_size);
    puts("快速排序后:");

    array_print(rand_array, max_size);

    for(int i = 0; i < max_size; i++){
        CU_ASSERT_EQUAL(rand_array[i], sorted[i]);
    }
}

int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    /* add a suite to the registry */
    pSuite = CU_add_suite("suite_sort", suite_init, suite_clean);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_sort", test_sort))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}
void array_print(int * array, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    puts("");
}