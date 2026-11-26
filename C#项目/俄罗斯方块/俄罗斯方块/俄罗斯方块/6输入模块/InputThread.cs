using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 俄罗斯方块
{
    class InputThread
    {
        //线程成员变量
        Thread inputThread;
        //声明输入检测事件
        public event Action inputEvent;
        private static InputThread instance = new InputThread();
        public static InputThread Instance
        {
            get { return instance; }
        }
        private InputThread()
        {
            inputThread = new Thread(InputCheck);
            inputThread.IsBackground = true;
            inputThread.Start();
        }
        private void InputCheck()
        {
            while (true)
            {
                if(inputEvent != null) 
                    inputEvent();   
            }
        }
    }
}
