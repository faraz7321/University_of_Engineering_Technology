using System;

namespace Week13
{
    class Driver
    {
        static void Main(string[] args)
        {
            BigInt a = new BigInt("1111",false);
            BigInt b = new BigInt("1111", false);
            BigInt c = new BigInt();
            c = a + b;
            Console.WriteLine(c.ToString());

        }
    }
}
