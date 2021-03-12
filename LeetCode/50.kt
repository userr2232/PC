fun myPow(x: Double, n: Int): Double {
    if(n == 0)
        return 1.0
    var x = x
    var halfN = n / 2
    if(n < 0) {
        x = 1 / x
        halfN *= -1
    }
    var exp: Double = myPow(x, halfN)
    if(n % 2 == 0) return exp * exp
    else return exp * exp * x
}

fun main() {
    println(myPow(2.00000, -2147483648))
}