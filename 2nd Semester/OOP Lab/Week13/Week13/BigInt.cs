using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Week13
{

    class BigInt
    {
        private List<int> digits;

        private bool Sign { get; set; }

        public BigInt(String number, bool Sign = false)
        {
            BigInt a = new BigInt();
            char[] arr = number.ToCharArray();
            int[] Aint = Array.ConvertAll(arr, c => (int)Char.GetNumericValue(c));
            if (arr[0] == '-')
            {
                a.Sign = true;
            }
            int l1 = Aint.Length;
            for (int i = l1 - 1; i >= 0; i--)
            {
                int c = Aint[i] - '0';
                a.digits.Add(c);
            }
        }

        public BigInt()
        {
            
        }

        public char getDigitAt(int index)
        {
            return '\0';
        }

        override
        public String ToString()
        {
            String x = "";
            for (int i = this.digits.Count - 1; i >= 0; i--)
                x=x+this.digits[i];
            return x;
        }

        public static BigInt operator +(BigInt a, BigInt b)
        {
            BigInt sum = new BigInt();
            int l1 = a.digits.Count, l2 = b.digits.Count;
            int len = l1 > l2 ? l1 : l2;
            int carry = 0;
            for (int i = 0; i < len; i++)
            {
                int d1 = 0, d2 = 0;
                try
                {
                    d1 = a.digits[i];
                }
                catch (Exception e) { }
                try
                {
                    d2 = b.digits[i];
                }
                catch (Exception e) { }
                int x = d1 + d2 + carry;
                sum.digits.Add(x % 10);
                carry = x / 10;
            }
            /* Adding carry */
            while (carry != 0)
            {
                sum.digits.Add(carry % 10);
                carry /= 10;
            }
            return sum;
        }

        public static BigInt operator -(BigInt a, BigInt b)
        {
            return null;
        }

        public static BigInt operator *(BigInt a, BigInt b)
        {
            return null;
        }

        public static BigInt operator /(BigInt a, BigInt b)
        {
            return null;
        }

        public static BigInt operator %(BigInt a, BigInt b)
        {
            return null;
        }
        public static BigInt operator -(BigInt a)
        {
            return null;
        }

        public static bool operator >(BigInt a, BigInt b)
        {
            return false;
        }

        public static bool operator <(BigInt a, BigInt b)
        {
            return false;
        }

        public static bool operator ==(BigInt a, BigInt b)
        {
            return false;
        }

        public static bool operator !=(BigInt a, BigInt b)
        {
            return false;
        }

        public static bool operator >=(BigInt a, BigInt b)
        {
            return false;
        }

        public static bool operator <=(BigInt a, BigInt b)
        {
            return false;
        }

        public static BigInt operator ++(BigInt a)
        {
            return null;
        }

        public static BigInt operator --(BigInt a)
        {
            return null;
        }

        public override bool Equals(object obj)
        {
            return false;
        }

        public override int GetHashCode()
        {
            return 0;
        }

        public List<char> ToBinary()
        {
            return null;
        }
    }
}
