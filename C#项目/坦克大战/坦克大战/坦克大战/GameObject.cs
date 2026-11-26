using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    abstract class GameObject
    {
        public int X { get; set; }
        public int Y { get; set; }
        public abstract Image GetImage();
        public int Width { get; set; }  
        public int Height { get; set; }
        public virtual void Draw()
        {
            Graphics g = GameFrameWork.g;
            g.DrawImage(GetImage(), X, Y);
        }
        public virtual void Update()
        {
            Draw();
        }
        public Rectangle GetRectangle()
        {
            Rectangle r = new Rectangle(X,Y,Width,Height);
            return r;
        }
    }
}
