package vote.laws.type;

import vote.laws.Laws;

import java.util.Objects;

public class Military extends Laws {
    private static final String type = "M";
    private final String result;
    private final int yes;
    private final int no;
    public Military(String name, int votesNeeded,String type,String result,int yesCount, int noCount) {
        super(name, votesNeeded);
        this.result=result;
        this.yes=yesCount;
        this.no=noCount;
    }


    @Override
    public String getType() {
        return "Military";
    }
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
