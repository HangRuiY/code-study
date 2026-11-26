using System;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;

#region 封装
//namespace C核心.封装
//{
//    #region 成员方法，构造，析构，垃圾回收
//    class Person
//    {
//        public string name;
//        public Person[] friends;
//        public Person(string name)
//        {
//            this.name = name;
//        }
//        public void AddFriends(Person p)
//        {
//            if (friends == null)
//            {
//                friends = new Person[] { p };
//            }
//            else
//            {
//                Person[] newArr = new Person[friends.Length + 1];
//                for (int i = 0; i < friends.Length; i++)
//                {
//                    newArr[i] = friends[i];
//                }
//                newArr[friends.Length] = p;
//                friends = newArr;
//            }
//        }
//        public void Speak()
//        {
//            for (int i = 0; i < friends.Length; i++)
//            {
//                Console.WriteLine(name + " " + friends[i].name);
//            }
//        }
//        //析构函数 是在垃圾被回收的时候调用，只变成垃圾不会调用
//        ~Person() { }
//        //垃圾回收GC,是通过遍历堆Heap内的动态开辟的数据，然后把那些不被调用或使用的数据回收释放
//        //GC只负责堆内的垃圾回收，栈中的是操作系统回收
//        //把内存分成0,1,2代内存，新分配的先去0代内存
//        //在每一轮回收开始时，会先从0代内存开始，标记哪些是垃圾，然后把重要的放到1代内存并编址，垃圾释放掉
//        //2代内存里面东西很多，称为大对象，目的是减少性能损耗，且大对象基本不搬迁（83kb）以上
//        //
//        //一般在游戏设计中，加载时会进行GC，且是程序手动GC
//        //GC.Collect();
//    }
//    #endregion
//    #region 成员属性，索引器
//    class Person2
//    {
//        public int money;
//        public string name;
//        public Person2[] friends;
//        public Person2(string name, int money)
//        {
//            this.name = name; this.money = money;
//        }
//        //成员属性可以解除3p的限制
//        //用帕斯卡命名法，大写
//        //让变量只获取不修改(get)，或者只修改不获取(set)
//        //而get和set前面都能加修饰符，默认使用函数前面的修饰符,且里面的修饰符级别低于外面的修饰符
//        //修饰符 返回类型 名称
//        //在get和set里面可以进行逻辑代码，实现加密
//        public int Money
//        {
//            get
//            {
//                return money;
//            }
//            set
//            {
//                money = value + 5;
//            }
//        }
//        //索引器：让对象可以像数组一样访问元素  修饰符 返回类型 this[参数类型1 参数1...];
//        //和成员属性一样，在get和set里面可以写逻辑
//        //也可以重载，结构体也支持
//        public Person2 this[int index]
//        {
//            get
//            {
//                if (friends == null || index > friends.Length - 1)
//                    return null;
//                else
//                    return friends[index];
//            }
//            set
//            {
//                if (friends == null)
//                {
//                    friends = new Person2[] { value };
//                }
//                else friends[index] = value;
//            }
//        }
//        public string this[string str]
//        {
//            get
//            {
//                switch (str)
//                {
//                    case "name": return name;
//                    default: return "";
//                }
//            }
//        }
//    }
//    #endregion

//    #region 静态成员
//    //静态成员用static修饰，调用时候用类名点出来使用
//    //通常在对于比较常用的变量或者方法，可以设置成静态，在使用时直接点出来
//    //
//    //为什么静态成员可以点出来？
//    //首先，程序中的量都是要在内存中生成空间的
//    //而静态成员，在程序开始时，会自动分配内存空间，且静态成员和程序共生死
//    class Test
//    {
//        public static float PI;// = 3.1415926f;
//        public int testInt = 100;
//        //静态方法，不能使用非静态成员（此时非静态变量没有分配内存）
//        //要使用，必须实例化（分配内存空间）
//        public static float Circle(float r)
//        {
//            Test t = new Test();
//            Console.WriteLine(t.testInt);
//            return PI * r * 2;
//        }
//        //常态函数可以调用静态成员
//        public void TestFunc()
//        {
//            Console.WriteLine(PI);//静态成员已经有了空间 
//            Console.WriteLine("213");
//        }
//    }
//    #endregion

//    #region 静态类，拓展方法
//    //唯一性，不能被实例化，只存在静态成员
//    static class StaticClass
//    {
//        public static int test1 = 100;
//        public static int test2 = 100;
//        public static void Speak()
//        {
//            Console.WriteLine(test1);
//        }
//        //静态构造函数  在静态类和普通类都可以有，无参数，不加修饰符,在函数内完成静态变量初始化
//        //在第一次使用类的时候，会自动调用仅一次静态构造函数
//        static StaticClass()
//        {
//            Console.WriteLine("调用构造函数");
//            test1 = 200;
//        }
//        //拓展方法，在静态类里面，给非静态类创建一个新的方法，只能给非静态类拓展
//        //如果拓展方法名字跟非静态类中的方法同名，会调用原先的那个方法
//        //修饰符 static 返回值 函数名(this 被拓展的类名 被拓展的类对象,参数类型1，参数1......)
//        public static void Tuozhan(this Common c, int t1, int t2)
//        {
//            Console.WriteLine("给Common拓展的方法，对像是:" + c.ToString());
//            c.test1 = t1;
//            Common.test2 = t2;
//        }
//    }
//    class Common
//    {
//        public int test1;
//        public static int test2;
//        public Common()
//        {
//            test1 = 100;
//            test2 = 200;
//        }
//        static Common()
//        {
//            Console.WriteLine("调用静态构造");
//            test2 = 100;
//        }
//    }
//    #endregion

//    #region 运算符重载
//    //修饰符 static 返回类型 operator 被重载的运算符 (参数列表)
//    //让自定义类型可以直接使用运算符 比如两个类对象相加
//    class Point
//    {
//        public int x; public int y;
//        public Point(int x, int y)
//        {
//            this.x = x;
//            this.y = y;
//        }
//        public static Point operator +(Point p1, Point p2)//至少有一个参数，要跟类一样
//        {
//            Point p = new Point(p1.x + p2.x, p1.y + p2.y);
//            return p;
//        }
//        public static bool operator ==(Point p1, Point p2)//等于和不等于一起出现
//        {
//            if (p1.x == p2.x && p1.y == p2.y) return true;
//            else return false;
//        }
//        public static bool operator !=(Point p1, Point p2)
//        {
//            if (p1.x == p2.x && p1.y == p2.y) return true;
//            else return false;
//        }
//    }
//    #endregion
//    class 封装
//    {
//        static void Main(string[] args)
//        {
//            #region 类的实例化
//            //Person p = null;Person p;//这两种实际上都是null
//            //Person p = new Person();//正常不带构造函数的实例化
//            #endregion

//            #region 成员方法调用
//            //Person p = new Person();
//            //p.name = "yrh";
//            //Person p2 = new Person();
//            //p2.name = "dhf";
//            //p.AddFriends(p2);
//            //p.Speak();
//            //Person p3 = new Person();
//            //p3.name = "xjhzzq";
//            //p.AddFriends(p3);
//            //p.Speak();
//            #endregion

//            #region 成员属性，索引器
//            //Person2 p = new Person2("yrh", 10);
//            //Person2 p2 = new Person2("zzr", 20);
//            //p.friends = new Person2[] { p2 };
//            //Console.WriteLine(p.name);
//            //Console.WriteLine(p[0].name);//让对象可以像数组一样访问元素  修饰符 返回类型 this[参数类型1 参数1...];
//            //Console.WriteLine(p["name"]);
//            #endregion

//            #region 静态成员和方法
//            //Test.PI = 3.14f;
//            //Console.WriteLine(Test.PI);
//            //Console.WriteLine(Test.Circle(2));
//            #endregion

//            #region 静态类和拓展方法
//            //StaticClass.Speak();
//            //Console.WriteLine(StaticClass.test1);
//            //Console.WriteLine(StaticClass.test2);
//            //Common c = new Common();
//            //Console.WriteLine(c.test1);
//            //Console.WriteLine(Common.test2);
//            //Common c = new Common();
//            //StaticClass.Tuozhan(c, 10, 20);//调用拓展方法
//            //Console.WriteLine(c.test1);
//            //Console.WriteLine(Common.test2);
//            ////或者
//            //c.Tuozhan(10, 20);
//            //Console.WriteLine(c.test1);
//            //Console.WriteLine(Common.test2);
//            #endregion

//            #region 运算符重载
//            //Point p = new Point(1,1);
//            //Point p2 = new Point(2,2);
//            //Point p3 = p + p2;
//            //Point p4 = new Point(3,3);
//            //if (p4 == p3)
//            //    Console.WriteLine("等于");
//            //else Console.WriteLine("不等于");
//            #endregion
//        }
//    }
//}
#endregion

#region 继承
//namespace C核心.继承
//{
//    #region 里氏替换原则,构造函数
//    //任何父类出现的地方，子类都可以代替，方便对象存储和管理
//    class GameObject
//    {
//        public string name;
//        public GameObject() { }
//        public GameObject(string name)
//        {
//            this.name = name;
//        }
//    }
//    class Player : GameObject
//    {
//        public int id;
//        //先调用基类的构造函数，再调用子类的构造函数
//        //父类的无参构造函数尽量有，如果不想写无参构造，必须用语法子类构造函数 : base(父类构造函数的参数列表)
//        public Player(int id,string name):base(name) { this.id = id; }
//        public void play()
//        {
//            Console.WriteLine(id + " " + name);
//            Console.WriteLine("玩家攻击");
//        }
//    }
//    #endregion

//    class 继承
//    {
//        static void Main(string[] args)
//        {
//            #region 里氏替换原则+构造函数
//            //GameObject player = new Player(1,"123");//用父类（基类）容器，装载子类对象
//            ////如果想通过父类容器调用子类方法，要用到is 和 as
//            //if(player is Player)//用is判断是不是制定的类 返回一个bool
//            //{
//            //    Player p = player as Player;//用as来返回一个对象值，如果不满足就是null
//            //    p.play();
//            //}
//            //GameObject[] objects = new GameObject[] { new Player(1,"123")};//里氏替换法则多用于数组情况
//            #endregion

//            #region 装箱拆箱
//            //用object存储值类型，把栈空间转移到堆空间
//            //把值类型取出来，把堆空间转回到栈空间
//            //可以写一个函数，参数是变长参数，然后类型是object，在函数内用逻辑去判断是哪个类型的，再做对应处理
//            //TestArray(1, 2f, 3, 4, 5, "123");
//            #endregion
//        }
//        //static void TestArray(params object[] array)
//        //{
//        //}
//    }
//}
#endregion

#region 多态
//namespace C核心.多态
//{
//    #region 多态的概念
//    //让继承同个父类的子类，在执行相同名字的方法时，有自己的唯一性
//    //vob 加虚函数virtual 子类重写override 子类保存父类base
//    class Father
//    {
//        public string name;
//        public Father(string name) { this.name = name; }
//        //虚函数 可以被子类重写
//        public virtual void Speak()
//        {
//            Console.WriteLine("Father的函数");
//        }
//    }
//    class Son : Father
//    {
//        public Son(string name) : base(name) { }
//        public override void Speak()
//        {
//            base.Speak();//可以用base来保存父类的方法
//            Console.WriteLine("Son的函数");
//        }
//    }
//    #endregion

//    #region 抽象类和抽象方法
//    //抽象类，不能被实例化，可以包含抽象方法，而抽象方法必须被继承的子类重写
//    //虚方法：加了virtual
//    //而抽象方法加了abstract,也可以叫纯虚方法
//    abstract class Thing
//    {
//        public string name;
//        public Thing(string name)
//        { this.name = name; }
//        public abstract void Speak();//父类的抽象方法不需要写逻辑，且不可被子类调用
//        public virtual void Speak2()//可以不重写
//        {
//            Console.WriteLine("调用虚方法");
//        }
//    }
//    class Test : Thing
//    {
//        public Test(string name) : base(name) { }
//        public override void Speak()
//        {
//            Console.WriteLine("使用纯虚方法打印名字{0}", name);
//        }
//        public override void Speak2()
//        {
//            Console.WriteLine("子类重写虚方法");
//        }
//    }
//    #endregion

//    #region 接口
//    //interface是行为的抽象规范，属于自定义类型
//    //不包含成员变量，只包含方法，索引器，属性，事件
//    //成员可以不用实现，并且可以省略修饰符，但不能用private修饰
//    //不能继承类，但是可以继承另一个接口
//    //
//    //类只能继承一个类，但是可以继承多个接口，且要实现接口内的所有成员
//    //即：接口是用来继承的，不能被实例化但是可以作为容器存储对象，和抽象类有类似
//    interface IFly
//    {
//        public void Fly();
//        public string Name { get; set; }
//        public int this[int index] { get; set; }
//    }
//    class Animal
//    {

//    }
//    class Person:Animal,IFly
//    {
//        //接口中的方法，在继承类中也能加v，再让子类重写
//        public virtual void Fly()
//        {
//            Console.WriteLine("人飞");
//        }
//        public string Name 
//        { 
//            get; 
//            set; 
//        }
//        public int this[int index] 
//        { 
//            get
//            {
//                return 0;
//            }
//            set
//            {

//            }
//        }
//    }
//    #endregion

//    #region 命名空间
//    //命名空间就像一个工具包，类就是一个个工具
//    //在新的命名空间里面写的各种类，要在程序最开头using一次，或者用命名空间名字点出来
//    //同个命名空间不能有同名类，不同的可以有同名类
//    //命名空间可以包裹命名空间
//    #endregion
//    class 多态
//    {
//        static void Main(string[] args)
//        {
//            #region 多态
//            //Father f = new Son("123");
//            //f.Speak();
//            #endregion

//            #region 抽象类和抽象方法
//            //Thing t = new Test("123");
//            //t.Speak();
//            //t.Speak2();
//            #endregion

//            #region 接口
//            //IFly f = new Person();
//            //f.Fly();
//            #endregion
//        }
//    }
//}
#endregion

#region 关联知识点
namespace 关联
{
    #region Object中的方法
    class Test
    {
        public int i = 1;
        public Test2 t2 = new Test2();
        public Test Clone()
        {
            return MemberwiseClone() as Test;
        }
    }
    class Test2
    {
        public int i = 2;
    }
    #endregion

    class 关联2
    {
        static void Main(string[] args)
        {
            #region Object中的方法
            ////两个静态方法用于比较值类型，引用类型是否相等，返回Bool
            ////GetType用于返回类型，和反射相关知识共同作用
            //Test t = new Test();
            //Type type = t.GetType();
            ////MemberwiseClone获取对象的浅拷贝，返回一个新的对象，这个新对象的"引用变量"和旧对象一样
            ////简单来说，克隆对象中的引用类型的改变会导致旧对象的引用类型变量也改变
            //Test t2 = t.Clone();
            //Console.WriteLine("克隆后:");
            //Console.WriteLine("t.i=" + t.i);//1
            //Console.WriteLine("t.t2.i=" + t.t2.i);//2
            //Console.WriteLine("t2.i=" + t2.i);//1
            //Console.WriteLine("t2.t2.i=" + t2.t2.i);//2
            //Console.WriteLine("改变克隆体后:");
            //t2.i = 3;
            //t2.t2.i = 4;
            //Console.WriteLine("t.i=" + t.i);//1
            //Console.WriteLine("t.t2.i=" + t.t2.i);//4
            //Console.WriteLine("t2.i=" + t2.i);//3
            //Console.WriteLine("t2.t2.i=" + t2.t2.i);//4
            ////虚方法ToString
            ////调用打印函数的时候，参数默认就是ToString后的字符串
            #endregion

            #region StringBuilder
            ////string是特殊的引用，每次生成新的string都会生成空间，因此改变string会浪费内存
            ////StringBuilder可以修改字符串且不生成新内存，使用前需要调用命名空间
            //StringBuilder sb = new StringBuilder("123123");
            ////StringBuilder在增加时，会自动扩容，也可能产生垃圾，但是比string少得多，容量会在上限时自动×2
            //Console.WriteLine(sb.Capacity);//查看容量
            //Console.WriteLine(sb.Length);//查看长度
            //sb.Append("ssss");//增加字符
            //Console.WriteLine(sb);

            //sb.Insert(2, "555");//插入 从下标为2的位置开始增加555
            //Console.WriteLine(sb);//125553123ssss

            //sb.Remove(1, 10);//删除 从下标为1的位置开始 删除10个字符
            //Console.WriteLine(sb);//1ss

            //sb[1] = 'a';//修改
            //Console.WriteLine(sb[1]);//查看 1as

            //sb.Replace("1", "2");//把str1改成str2  2as
            //Console.WriteLine(sb);

            //Console.WriteLine(sb.Equals("2as"));//比较相等
            //sb.Clear();//清空
            #endregion

            #region 如何选择结构体和类
            //1.想要用继承和多态时,直接淘汰结构体,比如玩家、怪物等等
            //2.对象是数据集合时,优先考虑结构体,比如位置、坐标等等
            //3.从值类型和引用类型赋值时的区别上去考虑,比如经常被赋值传递的对象,并且
            //改变赋值对象,原对象不想跟着变化时,就用结构体。比如坐标、向量、旋转等等
            #endregion

            #region 如何选择抽象类和接口
            //表示对象的用抽象类,表示行为拓展的用接口
            //不同对象拥有的共同行为,我们往往可以使用接口来实现
            //举个例子:
            //动物是一类对象,我们自然会选择抽象类;而飞翔是一个行为,我们自然会选择接口。
            #endregion
        }
    }
}
#endregion