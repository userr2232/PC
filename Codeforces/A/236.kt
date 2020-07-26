fun main() {
    val s = readLine()!!.toCharArray().toMutableSet()
    if(s.size % 2 == 1)
        println("IGNORE HIM!")
    else
        println("CHAT WITH HER!")
}