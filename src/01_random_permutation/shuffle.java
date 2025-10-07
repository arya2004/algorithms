import java.util.*;
public class Shuffle {
    public static <T> void fisherYates(List<T> a, Random rng) {
        for (int i = a.size() - 1; i > 0; --i) {
            int j = rng.nextInt(i + 1); // 0..i
            Collections.swap(a, i, j);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> a = new ArrayList<>();
        if (args.length > 0) a.addAll(Arrays.asList(args));
        else while (sc.hasNext()) a.add(sc.next());
        long seed = System.getenv().containsKey("SEED") ? Long.parseLong(System.getenv("SEED")) : new Random().nextLong();
        Random rng = new Random(seed);
        fisherYates(a, rng);
        System.out.println(String.join(" ", a));
    }
}
