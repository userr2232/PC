fun main() {
    val n = readLine()!!.toInt()
    var A = ""
    var count = 0
    var B = ""
    for(i in 1..n) {
        val tmp = readLine()!!
        if(i == 1) {
            A = tmp
            count++
        }
        else {
            if(tmp == A) count++
            else {
                B = tmp
                count--
            }
        }
    }
    if(count > 0) println(A)
    else println(B)
}