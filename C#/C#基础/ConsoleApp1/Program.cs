using System.CodeDom.Compiler;

namespace ConsoleApp1
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[][] arr = GenerateMatrix(3);
            for(int i=0;i< arr.GetLength(0); i++)
            {
                for(int j=0;j<arr[i].Length; j++)
                {
                    Console.Write(arr[i][j]+" ");
                }
                Console.WriteLine();
            }
        }
        public static int[][] GenerateMatrix(int n)
        {
            int[][] dir = { new int[] { 0, 1 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { -1, 0 } };
            int[][] matrix = new int[n][];
            int row = 0; int col = 0;
            int cur = 1;
            int index = 0;
            for (int i = 0; i < n; i++)
            {
                matrix[i] = new int[n];
            }
            while (cur <= n * n)
            {
                matrix[row][col] = cur;
                cur++;
                int nextrow = row + dir[index][0];
                int nextcol = col + dir[index][1];
                if (nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= n || matrix[nextrow][nextcol] != 0)
                {
                    index = (index + 1) % 4;
                }
                row += dir[index][0];
                col += dir[index][1];
            }
            return matrix;
        }
    }
}