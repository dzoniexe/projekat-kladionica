#ifndef SCHEDULE_HPP_INCLUDED
#define SCHEDULE_HPP_INCLUDED

for(int round = 0; round < rounds_count; round++)
{
    for(int match = 0; match < matches_per_round; match++)
    {
        int home = (round + match) % (teams_count - 1);
        int away = (teams_count - 1 - match + round) % (teams_count - 1);

        if(match == 0)
            away = teams_count - 1;

        matches.push_back(Match(&teams[home], &teams[away], round));
    }
}

#endif // SCHEDULE_HPP_INCLUDED
