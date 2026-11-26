using System;
using System.Collections;
using System.Reflection;
namespace Lesson3_Hash
{
    class MonsterMgr
    {
        private static Hashtable hs = new Hashtable();
        private static int MonsterId = 0;
        public static void Add()
        {
            Monster m = new Monster(MonsterId);
            MonsterId++;
            hs.Add(m.id, m);
        }
        public static void Remove(int id)
        {
            (hs[id] as Monster).Dead();
            Console.WriteLine("删除怪物{0}", id);
        }
    }
    class Monster
    {
        public int id;
        public Monster(int id)
        {
            this.id = id;
        }
        public void Dead()
        {
            Console.WriteLine("怪物{0}死了",id);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //哈希表又叫散列表，是基于键的哈希代码组织起来的 键-值对（用键来索引数据的值），用键来访问数据，提高效率
            Hashtable hs = new Hashtable();
            //增加  键和值都是Object类型 但是 键不能相同
            hs.Add(1, "123");
            hs.Add(true, "234");
            //删除 只能通过键来删除
            hs.Remove(1);
            //查看 通过键，通过值
            Console.WriteLine(hs[true]);
            hs.ContainsKey("123");
            hs.ContainsValue("123");
            //更改 只能改值，不能改键
            hs[true] = "123";
            //遍历 遍历键或者遍历值或者一起
            foreach(object item in hs.Keys)
            {
                Console.WriteLine(item + " "+ hs[item]);
            }
            foreach (object item in hs.Values)
            {
                Console.WriteLine(item);
            }
            foreach (object item in hs)
            {
                Console.WriteLine(item);//[True,123] 键值对
            }

            MonsterMgr.Add();
            MonsterMgr.Add();
            MonsterMgr.Add();
            MonsterMgr.Remove(2);
            Dictionary<int,int> cnt = new Dictionary<int,int>();
            cnt.TryAdd(1, 2);
        }
    }
}