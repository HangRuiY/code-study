using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    enum Direction
    {
        up,down, left, right
    }
    class Movething:GameObject
    {
        private Object _object = new Object();
        public Bitmap Bup { get; set; }
        public Bitmap Bdown { get; set; }
        public Bitmap Bleft { get; set; }
        public Bitmap Bright { get; set; }
        public bool IsMoving { get; set; }
        public int Speed { get; set; }
        public Direction dir;
        public Direction Dir 
        { 
            get
            {
                return dir;
            }
            set
            {
                dir=value;
                Bitmap b = null;//因为坦克的上下左右四个状态 图片的宽高不同，所以每次改变方向后，要记录宽高 便于检测是否碰壁
                switch (dir)
                {
                    case Direction.up:
                        b = Bup;
                        break;
                    case Direction.down:
                        b = Bdown;
                        break;
                    case Direction.left:
                        b = Bleft;
                        break;
                    case Direction.right:
                        b = Bright;
                        break;
                }
                lock (_object)
                {
                    Width = b.Width;
                    Height = b.Height;
                }
            }
        }
        public override void Draw()
        {
            lock (_object)
            {
                base.Draw();
            }
        }
        public override Image GetImage()
        {
            Bitmap bitmap = null;
            switch (Dir)
            {
                case Direction.up:
                    bitmap = Bup;
                    break;
                case Direction.down:
                    bitmap = Bdown;
                    break;
                case Direction.left:
                    bitmap = Bleft;
                    break;
                case Direction.right:
                    bitmap = Bright;
                    break;
            }
            bitmap.MakeTransparent(Color.Black);//设置背透明度
            return bitmap;
        }
    }
}
