using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 俄罗斯方块
{
    class BlockInfo
    {
        //方块信息坐标的容器
        private List<Position[]> list = new List<Position[]>();//每个元素是一个数组，数组中的元素记录了每一类方块中的小方块相对于中心方块的坐标信息
        public BlockInfo(E_DrawType type)//各种方块的坐标变化
        {
            switch (type)
            {
                case E_DrawType.cube:
                    list.Add(new Position[3] { new Position(2, 0), new Position(0, 1), new Position(2, 1) });
                    break;
                case E_DrawType.line:
                    list.Add(new Position[3] { new Position(0, -1), new Position(0, 1), new Position(0, 2) });
                    list.Add(new Position[3] { new Position(-4, 0), new Position(-2, 0), new Position(2, 0) });
                    list.Add(new Position[3] { new Position(0, -2), new Position(0, -1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(-2, 0), new Position(2, 0), new Position(4, 0) });
                    break;
                case E_DrawType.tank:
                    list.Add(new Position[3] { new Position(-2, 0), new Position(2, 0), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(-2, 0), new Position(0, -1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(-2, 0), new Position(2, 0), new Position(0, -1) });
                    list.Add(new Position[3] { new Position(2, 0), new Position(0, -1), new Position(0, 1) });
                    break;
                case E_DrawType.left_ladder:
                    list.Add(new Position[3] { new Position(0, -1), new Position(2, 0), new Position(2, 1) });
                    list.Add(new Position[3] { new Position(-2, 1), new Position(0, 1), new Position(2, 0) });
                    list.Add(new Position[3] { new Position(-2, -1), new Position(-2, 0), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(-2, 0), new Position(2, -1), new Position(0, -1) });
                    break;
                case E_DrawType.right_ladder:
                    list.Add(new Position[3]{new Position(0,-1),new Position(-2,0),new Position(-2,1)});
                    list.Add(new Position[3]{new Position(-2,-1),new Position(0,-1),new Position(2,0)});
                    list.Add(new Position[3]{new Position(2,-1),new Position(2,0),new Position(0,1)});
                    list.Add(new Position[3]{new Position(0,1),new Position(2,1),new Position(-2,0)});
                    break;
                case E_DrawType.left_long_ladder:
                    list.Add(new Position[3] { new Position(-2, -1), new Position(0, -1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(2, -1), new Position(-2, 0), new Position(2, 0) });
                    list.Add(new Position[3] { new Position(0, -1), new Position(2, 1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(2, 0), new Position(-2, 0), new Position(-2, 1) });
                    break;
                case E_DrawType.right_long_ladder:
                    list.Add(new Position[3] { new Position(0, -1), new Position(2, -1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(2, 0), new Position(-2, 0), new Position(2, 1) });
                    list.Add(new Position[3] { new Position(-2, 1), new Position(0, -1), new Position(0, 1) });
                    list.Add(new Position[3] { new Position(-2, 0), new Position(-2, -1), new Position(2, 0) });
                    break;
            }
        }
        public Position[] this[int index]//根据索引获取位置变化信息
        {
            get
            {
                if (index < 0)
                    return list[0];
                else if(index>=list.Count)
                    return list[list.Count-1];
                else 
                    return list[index];
            }
        }
        public int Count {  get { return list.Count; } }//获取形态数量，1种或4种
    }
}
