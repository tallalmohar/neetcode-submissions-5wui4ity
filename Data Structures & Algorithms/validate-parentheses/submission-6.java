class Solution {
    public boolean isValid(String s) {
        HashMap<Character,Character> m = new HashMap<>();
        m.put(']','[');
        m.put('}','{');
        m.put(')','(');
        Stack<Character> stack = new Stack<>();
        for(char c : s.toCharArray()){
            if(m.containsKey(c)){
                if(!stack.isEmpty() && stack.peek() == m.get(c)){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
