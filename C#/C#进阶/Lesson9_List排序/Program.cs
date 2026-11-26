using System;
namespace Lesson9_List排序
{
    class Monster
    {
        public int blood;
        public int atk;
        public int def;
        public int select;
        public Monster(int b,int a,int d)
        {
            this.blood = b;
            this.atk = a;
            this.def = d;
        }
        public override string ToString()
        {
            return string.Format("怪物血量：{0}，怪物攻击力：{1}，怪物防御力：{2}",this.blood,this.atk,this.def);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<Monster> list = new List<Monster>();
            Random rand = new Random();
            for(int i=0;i<10;i++)
            {
                list.Add(new Monster(rand.Next(100, 201), rand.Next(5, 11), rand.Next(50, 61)));
                Console.WriteLine(list[i]);
            }
            while(true)
            {
                int input = int.Parse(Console.ReadLine());
                switch (input)
                {
                    case 1:
                        list.Sort((a, b) =>
                        {
                            return a.atk>b.atk?1 : -1;
                        });
                        break;
                    case 2:
                        list.Sort((a, b) =>
                        {
                            return a.def > b.def ? 1 : -1;
                        });
                        break;
                    case 3:
                        list.Sort((a, b) =>
                        {
                            return a.blood > b.blood ? 1 : -1;
                        });
                        break;
                    case 4:
                        list.Reverse();
                        break;
                    case 0:
                        Console.WriteLine("退出");
                        break;
                }
                for(int i=0;i<10;i++)
                {
                    Console.WriteLine(list[i]);
                }
                if (input == 0)
                    break;
            }
        }

    }
}