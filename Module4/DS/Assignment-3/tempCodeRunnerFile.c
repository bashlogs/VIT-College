void infixtoprefix()
// {
//     char infix[20], prefix[20], *s, x;
//     printf("\n ENTER INFIX EXPREESION\n");
//     scanf("%s", infix);
//     int i = -1;
//     size_t size = sizeof(infix) / sizeof(infix[0]);
//     strrev(infix);
//     printf("\n%s", infix);
//     s = infix;
//     while (*s != '\0')
//     {
//         if (isalnum(*s))
//             prefix[++i] = *s;
//         else if (*s == ')')
//             push(*s);
//         else if (*s == '(')
//             while ((x = pop()) != ')')
//                 prefix[++i] = x;
//         else
//         {
//             while (priority(stack[top]) >= priority(*s))
//                 prefix[++i] = pop();

//             push(*s);
//         }
//         s++;
//     }
//     while (top != -1)
//         prefix[++i] = pop();

//     strrev(prefix);
//     prefix[++i] = '\0';

//     printf("\n%s", prefix);
// }