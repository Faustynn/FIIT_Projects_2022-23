package classes;
import java.util.ArrayList;
import java.util.List;

public class MySeparator extends Separator {
    @Override
    public List<String> separate(String input) {
        List<String> result = new ArrayList<>();

        String[] parts = input.split(";");
        for (String part : parts) {
            result.add(part.trim());
        }

        return result;
    }
}