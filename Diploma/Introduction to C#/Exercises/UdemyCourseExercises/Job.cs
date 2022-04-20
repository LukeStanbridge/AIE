using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UdemyCourseExercises
{
    internal class Job
    {
        private string jobDescription;
        private double jobTime;
        private double rateCharged;
        private double totalFee;
        
        public Job (string description, double time, double rate)
        {
            JobDescription = description;
            JobTime = time;
            RateCharged = rate;
        }

        public string JobDescription
        {
            get { return jobDescription; }
            set { jobDescription = value; }
        }

        public double JobTime
        {
            get { return jobTime; }
            set { jobTime = value; CalcJobCost(); }
        }

        public double RateCharged
        {
            get { return rateCharged; }
            set { rateCharged = value; CalcJobCost(); }
        }

        public double TotalFee
        {
            get { return totalFee; }
        }

        public static Job operator +(Job job1, Job job2)
        {
            string newJobDescription = job1.JobDescription + " and " + job2.JobDescription;
            double newjobTime = job1.JobTime + job2.JobTime;
            double newRateCharged = (job1.RateCharged + job2.RateCharged) / 2;

            Job addedJob = new Job(newJobDescription, newjobTime, newRateCharged);
            return addedJob;
        }

        private void CalcJobCost()
        {
            totalFee = jobTime * rateCharged;
        }
    }
}
