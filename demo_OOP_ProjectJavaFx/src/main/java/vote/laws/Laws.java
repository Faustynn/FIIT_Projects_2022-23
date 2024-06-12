package vote.laws;

import java.util.Objects;

public class Laws {
    private String name;
    private int votesNeeded;
    private int votesFor;
    private int votesAgainst;
    private int yes;
    private int no;

    public Laws(String name, int votesNeeded) {
        this.name = name;
        this.votesNeeded = votesNeeded;
        this.votesFor = 0;
        this.votesAgainst = 0;
    }

    public Laws() {

    }


    public String getName() {
        return name;
    }

    public int getVotesNeeded() {
        return votesNeeded;
    }

    public int getVotesFor() {
        return votesFor;
    }

    public int getVotesAgainst() {
        return votesAgainst;
    }

    public void voteFor() {
        votesFor++;
    }

    public void voteAgainst() {
        votesAgainst++;
    }

    public String getResult(){
        return "";
    }
    public String getType(){
       return "";
    }
    public int getYes(){
        return 0;
    }
    public int getNo(){
        return 0;
    }
}
