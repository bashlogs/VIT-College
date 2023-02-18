#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *productName[] = {"sugar", "milk", "vegetable masala", "washing powder", "salt", "poha", "oil", "tooth paste", "hair conditionar", "wheat flour", "red chilli", "maida", "coffee", "tea", "butter", "milk powder", "turmeric powder", "hair oil", "ghee", "face powder"};
char product_name[19][20];
int product_quantity[19];
int count1 = 0, total_bill = 0, total_bill1 = 0, discount;
int sugar_p = 50, milk_p = 50, vegetable_masala_p = 50, wahing_powder_p = 100, salt_p = 20, poha_p = 50, oil_p = 200, tooth_paste_p = 40, hair_conditionar_p = 120, wheat_flour_p = 50, red_chilli_p = 40, maida_p = 45, coffee_p = 200, tea_p = 100, butter_p = 100, milk_powder_p = 150, turnmeric_powder_p = 200, hair_oil_p = 60, ghee_p = 300, face_powder_p = 70;
void generate_bill()
{
    printf("\n\t    **** GROCERY STORE BILL ****\n");
    printf("|--------------------------------------------------------\n");
    printf("|  Product\t\tQuantity\t\tPrice   |\n");
    printf("|--------------------------------------------------------\n");
    for (int i = 0; i < count1; i++)
    {
        if (!strcmp("sugar", product_name[i]))
        {
            printf("|  %s           \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], sugar_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("milk", product_name[i]))
        {
            printf("|  %s            \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], milk_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("vegetable masala", product_name[i]))
        {
            printf("|  %s     \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], vegetable_masala_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("washing powder", product_name[i]))
        {
            printf("|  %s      \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], wahing_powder_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("salt", product_name[i]))
        {
            printf("|  %s            \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], salt_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("poha", product_name[i]))
        {
            printf("|  %s            \t%dkg    \t\t%d  \n", product_name[i], product_quantity[i], poha_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("oil", product_name[i]))
        {
            printf("|  %s                 \t%dltr      \t\t%d  \n", product_name[i], product_quantity[i], oil_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("tooth paste", product_name[i]))
        {
            printf("|  %s          \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], tooth_paste_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("hair conditionar", product_name[i]))
        {
            printf("|  %s    \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], hair_conditionar_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("wheat flour", product_name[i]))
        {
            printf("|  %s       \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], wheat_flour_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("red chilli", product_name[i]))
        {
            printf("|  %s           \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], red_chilli_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("maida", product_name[i]))
        {
            printf("|  %s                \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], maida_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("coffee", product_name[i]))
        {
            printf("|  %s          \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], coffee_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("tea", product_name[i]))
        {
            printf("|  %s             \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], tea_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("butter", product_name[i]))
        {
            printf("|  %s               \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], butter_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("milk powder", product_name[i]))
        {
            printf("|  %s          \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], milk_powder_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("turmeric powder", product_name[i]))
        {
            printf("|  %s      \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], turnmeric_powder_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("hair oil", product_name[i]))
        {
            printf("|  %s            \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], hair_oil_p*product_quantity[i]);
            printf("|--------------------------------------------------------\n");
        }
        else if (!strcmp("ghee", product_name[i]))
        {
            printf("|  %s               \t%dkg     \t\t%d  \n", product_name[i], product_quantity[i], ghee_p*product_quantity[i]);
            printf("|-------------------------------------------------------\n");
        }
        else if (!strcmp("face powder", product_name[i]))
        {
            printf("|  %s          \t%dpac      \t\t%d  \n", product_name[i], product_quantity[i], face_powder_p*product_quantity[i]);
            printf("|-------------------------------------------------------\n");
        }
    }
    printf("| Total product %d \t\tTotal amount    %d\n", count1, total_bill1);
    printf("|--------------------------------------------------------\n");
    printf("|                  \t\tDiscount        %d\n", discount);
    printf("|--------------------------------------------------------\n");
    printf("|                  \t\tPayable ammount %d\n", total_bill);
    printf("|--------------------------------------------------------\n");
}
void calculate_bill()
{
    char choose;
    for (int i = 0; i < count1; i++)
    {
        if (!strcmp("sugar", product_name[i]))
        {
            total_bill += sugar_p * product_quantity[i];
        }
        else if (!strcmp("milk", product_name[i]))
        {
            total_bill += milk_p * product_quantity[i];
        }
        else if (!strcmp("vegetable masala", product_name[i]))
        {
            total_bill += vegetable_masala_p * product_quantity[i];
        }
        else if (!strcmp("washing powder", product_name[i]))
        {
            total_bill += wahing_powder_p * product_quantity[i];
        }
        else if (!strcmp("salt", product_name[i]))
        {
            total_bill += salt_p * product_quantity[i];
        }
        else if (!strcmp("poha", product_name[i]))
        {
            total_bill += poha_p * product_quantity[i];
        }
        else if (!strcmp("oil", product_name[i]))
        {
            total_bill += oil_p * product_quantity[i];
        }
        else if (!strcmp("tooth paste", product_name[i]))
        {
            total_bill += tooth_paste_p * product_quantity[i];
        }
        else if (!strcmp("hair conditionar", product_name[i]))
        {
            total_bill += hair_conditionar_p * product_quantity[i];
        }
        else if (!strcmp("wheat flour", product_name[i]))
        {
            total_bill += wheat_flour_p * product_quantity[i];
        }
        else if (!strcmp("red chilli", product_name[i]))
        {
            total_bill += red_chilli_p * product_quantity[i];
        }
        else if (!strcmp("maida", product_name[i]))
        {
            total_bill += maida_p * product_quantity[i];
        }
        else if (!strcmp("coffee", product_name[i]))
        {
            total_bill += coffee_p * product_quantity[i];
        }
        else if (!strcmp("tea", product_name[i]))
        {
            total_bill += tea_p * product_quantity[i];
        }
        else if (!strcmp("butter", product_name[i]))
        {
            total_bill += butter_p * product_quantity[i];
        }
        else if (!strcmp("milk powder", product_name[i]))
        {
            total_bill += milk_powder_p * product_quantity[i];
        }
        else if (!strcmp("turmeric powder", product_name[i]))
        {
            total_bill += turnmeric_powder_p * product_quantity[i];
        }
        else if (!strcmp("hair oil", product_name[i]))
        {
            total_bill += hair_oil_p * product_quantity[i];
        }
        else if (!strcmp("ghee", product_name[i]))
        {
            total_bill += ghee_p * product_quantity[i];
        }
        else if (!strcmp("face powder", product_name[i]))
        {
            total_bill += face_powder_p * product_quantity[i];
        }
    }
    total_bill1 = total_bill;
repeate:
    printf("\nIf you want to generate your bill then press 'Y' otherwise 'N': ");
    fflush(stdin);
    scanf("%c", &choose);
    if (choose == 'Y' || choose == 'y')
    {
        generate_bill();
    }
    else if (choose == 'N' || choose == 'n')
    {
        exit(0);
    }
    else
    {
        printf("Invalid character tyr again\n");
        goto repeate;
    }
}
void main()
{
    char ch, temp_str[20];
    int check,count=0;
    for (int i = 0; i < 20; i++)
    {

    repeate1:
        count=0;
        printf("Enter product name : ");
        fflush(stdin);
        gets(temp_str);
        for (int j = 0; j < 20; j++)
        {
            check = strcmp(temp_str, productName[j]);
            if (check == 0)
            {
                strcpy(product_name[count1], temp_str);
            }
            else
            {
                count++;
                if (count == 20)
                {
                    printf("Invalid product name\n");
                    goto repeate1;
                }
            }
        }
    repeate2:
        printf("Enter quantity : ");
        scanf("%d", &product_quantity[count1]);
        if (product_quantity[count1] < 1)
        {
            printf("Invalid quantity try again\n");
            goto repeate2;
        }
        count1++;
    repeate:
        printf("If you have entered all product then Press 'Y' otherwise 'N' :");
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            calculate_bill();
            exit(0);
        }else if (ch=='N'||ch=='n')
        {
            printf("");
        }        
        else
        {
            printf("Invalid press try again\n");
            goto repeate;
        }
    }
    printf("\nWe have only 20 product\n\n");
    calculate_bill();
}
