fun main() {
    readLine()
    var A = 0
    readLine()!!.toCharArray().forEach{
        if(it == 'A') A++;
        else A--;
    }
    if(A == 0)
        println("Friendship")
    else if(A > 0)
        println("Anton")
    else
        println("Danik")
}