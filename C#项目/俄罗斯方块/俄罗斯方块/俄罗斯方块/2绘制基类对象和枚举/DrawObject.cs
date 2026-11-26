using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 俄罗斯方块
{
    //绘制类型 根据不同类型改变方块颜色
    enum E_DrawType
    {
        wall,//墙壁
        cube,//正方形
        line,//直线
        tank,//T型
        left_ladder,//左楼梯
        right_ladder,//右楼梯 
        left_long_ladder,//左长楼梯
        right_long_ladder,//右长楼梯 
    }
    class DrawObject : IDraw
    {
        public Position pos;
        public E_DrawType drawType;
        public DrawObject(E_DrawType drawType)
        {
            this.drawType = drawType;
        }
        public DrawObject(E_DrawType drawType,int x,int y):this(drawType)
        {
            this.pos = new Position(x,y);
        }
        public void Draw()
        {
            if (pos.y < 0) return;
            Console.SetCursorPosition(pos.x,pos.y);
            switch (drawType)
            {
                case E_DrawType.wall:
                    Console.ForegroundColor = ConsoleColor.White;
                    break;
                case E_DrawType.cube:
                    Console.ForegroundColor = ConsoleColor.Red;
                    break;
                case E_DrawType.line:
                    Console.ForegroundColor = ConsoleColor.Green;   
                    break;
                case E_DrawType.tank:
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    break;
                case E_DrawType.left_ladder:
                case E_DrawType.right_ladder:
                    Console.ForegroundColor = ConsoleColor.DarkGreen;
                    break;
                case E_DrawType.left_long_ladder:
                case E_DrawType.right_long_ladder:
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    break;
            }
            Console.Write("■");
        }
        //切换方块类型，用于方块下落到地图时，把方块变成墙壁类型
        public void ChangeType(E_DrawType drawType)
        {
            this.drawType = drawType;
        }
        //清除绘制
        public void Clean()
        {
            if (pos.y < 0) return;
            Console.SetCursorPosition(pos.x,pos .y);
            Console.Write("  ");
        }
    }
}
