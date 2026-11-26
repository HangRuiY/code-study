using System;
using System.Runtime.CompilerServices;
namespace C基础
{
    #region 枚举
    enum E_sex
    {
        man,
        woman
    }
    enum E_care
    {
        zhanshi,
        lieren,
        fashi
    }
    #endregion

    #region 结构体
    struct Student
    {
        //有权限public,private,protect，默认是私有，只能在结构体内部使用
        //变量 结构体中的变量不能直接初始化
        public int age;
        public string sex;
        public string name;
        //构造函数（可选）
        public Student(int age, string sex,string name)
        {
            this.age = age;
            this.sex = sex;
            this.name = name;
        }
        //函数
        public void Speak()
        {
            Console.WriteLine("我的名字是:"+name);
        }
    }
    #endregion
    class Father
    {
        public string name;
        public Father() { }
        public Father(string name)
        {
            this.name = name;
        }
        public virtual void Speak()
        {
            Console.WriteLine("sss");
        }
    }
    class Son:Father
    {
        public int age;
        public Son(string name,int age):base(name)
        {
            this.age = age;
        }
        public void Speak()
        {
            Console.WriteLine("111");
        }
    }
    class Program
    {     
        #region 函数
        static int[] Test(int a,int b)
        {
            return new int[] {a,b};
        }
        #endregion

        #region ref和out
        static void ChangeValue(ref int num)
        {
            num = 2;
        }
        static void ChangeValue(out int[] arr)
        {
            arr = new int[3] { 10, 20, 30 };
        }
        #endregion

        #region 变长关键字 params
        static void Test2(string test = "可",params int[] arr)
        {
            int sum = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                sum += arr[i];
            }
            Console.WriteLine(test + sum);
        }
        #endregion

        #region 递归
        //完成0-10
        static void func(int a)
        {
            if(a>10)//4.条件判断
            {
                return;
            }
            Console.WriteLine(a);//3.打印
            a++;//2.进行变化
            func(a);//1.构造递归
        }
        #endregion 

        static void Main(string[] args)
        {
            Father son = new Son("yrh", 12);
            son.Speak();
            Son s = son as Son;
            s.Speak();
            #region 输入输出
            //Console.WriteLine("Hello"); //自动空行
            //Console.Write("hello");//不空行
            //Console.WriteLine(); //自动空行
            //Console.ReadLine();//等待输入 回车结束
            //Console.ReadKey();//按下按键便结束
            #endregion

            #region 转义字符
            // \+任意字符，就是转义字符
            //单引号\' 双引号\" 换行\n 斜杠\\
            //Console.WriteLine("好好好\\2");//如果只是\2，那么整体会被认为是转义字符而报错，\\2将第二个\当做字符输出
            //制表符\t 光标退格\b 空字符\0 警报音\a
            #endregion

            #region 类型转换
            ////把字符串转换成其他类型
            //int i = int.Parse("123");
            ////把各种类型转换成各种类型
            //string j = Convert.ToString(123);
            //Console.WriteLine(j);
            ////用ToString将任何类型转化为字符串
            //Console.WriteLine(50.ToString());
            #endregion

            #region 异常捕获
            //异常捕获 防止卡死，在出错的时候执行catch中的代码
            //try
            //{
            //    string str = Console.ReadLine();
            //    int i = Convert.ToInt32(str);
            //    Console.WriteLine(i);
            //}
            //catch
            //{
            //    Console.WriteLine("输入错误");
            //}
            //finally
            //{
            //    Console.WriteLine("执行完毕");
            //}
            #endregion

            #region 浮点数
            //float类型在定义时需要加f，因为默认是double类型。
            //double sum = 12.0;
            //double sum2 = sum * 2.1d;
            //Console.WriteLine(sum2+" "+sum2.ToString());
            #endregion

            #region 枚举
            //使用枚举
            //Console.WriteLine("请选择性别:");
            //E_sex sex = (E_sex)int.Parse(Console.ReadLine());
            //string ssex = "";
            //int atk = 0;
            //int dfs = 0;
            //switch (sex)
            //{
            //    case E_sex.man:
            //        ssex = "男性";
            //        atk += 50;dfs += 100;
            //        break;
            //    case E_sex.woman:
            //        ssex = "女性";
            //        atk += 150;dfs += 20;
            //        break;
            //}
            //Console.WriteLine("请选择职业:");
            //E_care care = (E_care)int.Parse(Console.ReadLine());
            //string carename = "";
            //string skill = "";
            //switch (care)
            //{
            //    case E_care.zhanshi:
            //        carename = "战士";skill = "冲撞";
            //        break;
            //    case E_care.lieren:
            //        carename = "猎人";skill = "射箭";
            //        break;
            //    case E_care.fashi:
            //        carename = "法师";skill = "激光";
            //        break;
            //}
            //Console.WriteLine("你选择了\"{0}{1}\",攻击力:{2},防御力:{3},技能:{4}", ssex, carename,atk,dfs,skill);
            #endregion

            #region 数组
            //一维数组
            //int[] arr;
            //int[] arr0 = { 1, 2, 3, 4, 5 };
            //int[] arr1 = new int[5];
            //int[] arr2 = new int[5] { 1, 2, 3, 4, 5 };
            //Console.WriteLine(arr2.Length);
            //二维数组
            //int[] arr3 = new int[] { 1, 2, 3, };
            //int[,] arr4;
            //int[,] arr5 = { { 1, 2, 3 }, { 1, 2, 3 } };
            //int[,] arr6 = new int[2, 3];
            //int[,] arr7 = new int[2, 3] { { 1,2,3},{1,2,3 }};
            //Console.WriteLine(arr7.GetLength(0));//得到行数
            //Console.WriteLine(arr7.GetLength(1));//得到列数
            //交错数组 存储同一类型，m行但是每一列不一定相同的数据，相当于每一行都是一个一维数组
            //int[][] a = { new int[] { 1, 2, 3 }, new int[] { 1, 2, 3 }, new int[] { 1, 2, 3 } };
            //int[][] b = new int[3][] { new int[] { 1, 2, 3 }, new int[] { 1, 3 }, new int[] { 1, 2, 3 } };
            //Console.WriteLine(a.GetLength(0));//得到行数
            //Console.WriteLine(b[1].Length);   //得到某一行的列数
            #endregion

            #region 值类型和引用类型
            //int a = 10;
            //引用类型
            //int[] arr = new int[] { 1, 2, 3, 4 };
            //int b = a;
            //int[] arr2 = arr;
            //Console.WriteLine("a={0}, b={1}", a, b); //10  10
            //Console.WriteLine("arr[0]={0}, arr2[0]={1}", arr[0], arr2[0]);// 1  1
            //b = 20;
            //arr2[0] = 5;
            //Console.WriteLine("修改了b和arr2[0]之后");
            //Console.WriteLine("a={0}, b={1}", a, b);// 10  20
            //Console.WriteLine("arr[0]={0}, arr2[0]={1}", arr[0], arr2[0]);//5  5 
            //值类型 在相互赋值时 把内容拷贝给了对方 它变我不变    
            //引用类型的相互赋值 让两者指向同一个值 它变我也变  但是string不会受影响
            //值类型 和 引用类型 存储在的 内存区域 是不同的 存储方式是不同的
            //值类型存储在    栈空间  系统分配,自动回收,小而快
            //引用类型 存储在 堆空间  手动申请和释放,大而慢
            #endregion

            #region string类型
            //string是引用类型，但是它变我不变，在栈生成地址的同时，堆区也会有新空间
            //因此，**string最好不要连续赋值，因为赋新值会让旧值变成内存垃圾**
            //string str = "123";
            //string str2 = str;
            //str2 = "321";
            //Console.WriteLine(str);// 123
            //Console.WriteLine(str2);// 321 
            #endregion

            #region 使用函数
            //int[] arr = Test(2, 3);
            //Console.WriteLine(arr[0] + " " + arr[1]);
            #endregion

            #region ref和out
            //ref 和 out :在函数内部 改变来自外部输入的值 里面变了 外面也跟着变
            //ref传入的变量必须初始化，out不用  ref买票上车
            //out传入的变量必须在函数内部赋值，ref不用  out上车买票
            //int a = 1;
            //ChangeValue(ref a);
            //Console.WriteLine(a);
            //int[] arr = { 1,2,3};
            //ChangeValue(out arr);
            //Console.WriteLine(arr[0]);
            #endregion

            #region 变长参数关键字 和 默认参数值
            //params 后面 必须跟数组 params 类型[] 数组名
            //函数参数中，可以有多个参数，且params参数必须在最后一个，且仅有一个params
            //Test2(" ",1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
            #endregion

            #region 递归
            //完成0-10
            //func(0);
            #endregion

            #region 结构体
            //Student s = new Student(20, "女", "小红");
            //s.Speak();
            #endregion

            #region 冒泡排序 带优化
            int[] arr = { 8, 7, 50, 1, 4, 3, 6, 9, 45, 80, 25 };
            bool ifsort = false;
            //有n个数 比较n-1轮
            for (int j = 0; j < arr.Length-1; j++)
            {
                ifsort = false;
                //第i个和第i+1个比较
                //而每一轮比较完，都能确定一个新的大数，所以每一轮比较的次数会减1
                for (int i = 0; i < arr.Length - 1 - j; i++)
                {
                    if (arr[i] >= arr[i + 1])
                    {
                        ifsort = true;
                        int t = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = t;
                    }
                }
                //当一轮比较完，ifsort还是false，说明已经不需要比较了
                if (!ifsort)
                    break;
            }
            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine(arr[i]);
            }
            #endregion

            #region 选择排序 带优化
            //int[] arr = { 8, 7, 50, 1, 4, 3, 6, 9, 45, 80, 25 };
            ////n个数，排n轮
            //for(int i=0;i<arr.Length;i++)
            //{
            //    //中间商下标
            //    int index = 0;
            //    //跟第二个开始比较 比完一轮 更新极值
            //    //减去i是为了排除已经排好的数
            //    for (int j = 1; j < arr.Length - i; j++)
            //    {
            //        if (arr[index] < arr[j])
            //        {
            //            index = j;
            //        }
            //    }
            //    //放入目标位置 如果当前所在位置就是目标位置，那么没必要交换
            //    if (index != arr.Length - 1 - i)
            //    {
            //        int t = arr[index];
            //        arr[index] = arr[arr.Length - 1 - i];
            //        arr[arr.Length - 1 - i] = t;
            //    }
            //}
            //for(int i =0;i<arr.Length;i++)
            //{
            //    Console.WriteLine(arr[i]);
            //}
            #endregion
        }
    }

}