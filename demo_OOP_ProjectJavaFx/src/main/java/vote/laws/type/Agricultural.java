package vote.laws.type;

import vote.laws.Laws;
import java.util.Objects;

public class Agricultural extends Laws {
    private static final String type = "A";
    private final String result;
    private final int yes;
    private final int no;
    public Agricultural(String name, int votesNeeded,String type,String result, int yesCount, int noCount) {
        super(name, votesNeeded);
        this.result=result;
        this.yes=yesCount;
        this.no=noCount;
    }

    @Override
    public String getType() {
        return "Agricultural";
    }
    @Override
    public String getResult() {
        return result;
    }
    @Override
    public int getYes() {
        return yes;
    }
    @Override
    public int getNo() {
        return no;
    }
}
