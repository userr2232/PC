import kotlin.system.exitProcess

fun main() {
    var arr = IntArray(26)
    for(i in 1..2) {
        readLine()!!.toCharArray().let {
            for(x in it) {
                arr[x - 'A']++
            }
        }
    }
    readLine()!!.toCharArray().let {
        for(x in it) {
            arr[x - 'A']--
        }
    }
    for(x in arr) {
        if(x != 0) {
            println("NO")
            exitProcess(0)
        }
    }
    println("YES")
}