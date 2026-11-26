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

            //中央提示 用队列
            Queue q = new Queue();
            q.Enqueue("消息1");
            q.Enqueue("消息2");
            q.Enqueue("消息3");
            int index = 0;
            while(q.Count>0)
            {
                if(index % 99999 == 0)
                {
                    Console.WriteLine(q.Dequeue());
                    index = 0;
                }
                index++;
            }
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