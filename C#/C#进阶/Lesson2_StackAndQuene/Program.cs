using System;
using System.Collections;
namespace Lesson2_StackAndQueue
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack stack = new Stack();
            Calc(13, ref stack);
            for (int i = stack.Count; i > 0; i--)
            {
                Console.Write(stack.Pop());
            }

            Queue Q = new Queue();

        }

        static void Calc(int num, ref Stack stack)
        {
            while (true)
            {
                //4  100
                //11        1011
                stack.Push(num % 2);
                num /= 2;
                if (num == 1)
                {
                    stack.Push(num);
                    break;
                }
            }
        }
    }
}