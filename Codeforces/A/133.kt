fun main() {
    if(readLine()!!.toCharArray().indexOfFirst{ c -> c == 'H' || c == 'Q' || c == '9' } >= 0)
        println("YES")
    else
        println("NO")
}